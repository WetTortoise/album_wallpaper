#include "header.h"
#include <iostream>


// todo - will need to add a search for singles/compilation/ep function, not sure if i still want this feature but its here if i change my mind  
void current_albums(){

} 

void change_wallpaper(std::string filename){


}


void download_url(std::string url){
    /*  
    Wallpapers
        => Temp
            Spotify
                filename.jpg
            Itunes 
                filename.jpg
        
        =>  Finished - after added then remove temp files
            filename.jpg

    */
}



void random_albums(int sleep_amount){
    refresh_access();
    std::vector<std::unordered_map<std::string, std::string>> a = get_unique_albums();
    for (auto album : a) {    
        // the reason why i'm only searching for albums is because sometimes spotify and apple might have different releases for singles, sometimes spotify might classify something as a single whilst apple hasnt got it as a single 
        if (album["album_type"] == "album"){ 
            //std::cout << album["name"] << "\n";
            int artist_id = Itunes().get_id(album["artist"]);
            if (artist_id == 1){
                std::cout << "Couldn't find artist: "  << album["artist"] << "\n";
            }else{
                auto albums = Itunes().get_albums(std::to_string(artist_id));
                auto found = Itunes().find_album(album["name"],albums);
                if (found.size() > 0){
                    auto u = Itunes().uncompressed(found[0]);
                    // change wallpaper 
                    std::cout << album["name"] << " " << found[0]["collectionName"] << " " << album["image"] << " " << u.str() << " "  << "\n";
                }else{
                    std::cout << "couldn't find " << album["name"] << "\n";
                }
            } 
        }
        // sleep
    }
}









void main() {
    /*  check if spotify has the right credentials in the file 
        if not then start the process for the user to add in their credentials input() and get auth tokens 

        create wallpaper folders if its not already created 
        



    */


    while (true){
        random_albums(1);
    }

}