#include <iostream>
#include <cstring>    
#include <ctime>        
#include <thread>        
#include <chrono>
#include <discord_rpc.h>

void handleDiscordReady(const DiscordUser* request) {
    std::cout << "Discord: ready!" << std::endl;
}

void handleDiscordDisconnected(int errcode, const char* message) {
    std::cerr << "Discord: disconnected (" << errcode << "): " << message << std::endl;
}

void handleDiscordError(int errcode, const char* message) {
    std::cerr << "Discord: error (" << errcode << "): " << message << std::endl;
}

int main() {
    DiscordEventHandlers handlers;
    memset(&handlers, 0, sizeof(handlers));
    handlers.ready = handleDiscordReady;
    handlers.disconnected = handleDiscordDisconnected;
    handlers.errored = handleDiscordError;

    Discord_Initialize("1280593191648624772", &handlers, 1, NULL);

    DiscordRichPresence discordPresence;
    memset(&discordPresence, 0, sizeof(discordPresence));
    discordPresence.state = "Playing";
    discordPresence.details = "Coding a C++ app";
    discordPresence.startTimestamp = std::time(nullptr);
    discordPresence.endTimestamp = std::time(nullptr) + 5 * 60;
    discordPresence.largeImageKey = "large_image";
    discordPresence.smallImageKey = "small_image";
    Discord_UpdatePresence(&discordPresence);

    while (true) {
        Discord_RunCallbacks();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }

    Discord_Shutdown();
    return 0;
}
