Author: Fatema Lokhandwala

Overview:
This program is a video service called ViewTube. ViewTube stores Channels, and these Channels contain Videos that can be “played”. ViewTube will have functions to add, view, and remove Channels and Videos. In addition there is a Client class that can “download” a Channel, and then play the Videos it contains. 

List of files:
- README.txt: Contains this description
- Channel.h and Channel.cc: Contains information about the Channel such as title and owner. Manages a collection of Videos.
- ChannelList.h and ChannelList.cc: It is a data structure for Channels.
- Client.h and Client.cc: Prints error messages. Downloads copies of Channel and views Videos locally.
- Control.h and Control.cc: Responsible for managing the interactions of other objects. 
- Date.h and Date.cc: Contains information about the date.
- defs.h: Contains preprocessor constants.
- Video.h and Video.cc: Contains information about the Video such as title, content and date added.
- VideoList.h and VideoList.cc: It is a data structure for Videos.
- View.h and View.cc: Presents a menu and takes input from the user.
- ViewTube.h and ViewTube.cc: Manages a collection of Channels. Provides functions to add, delete, access, and print Channels and the Videos the Channels manage. Prints error messages.
- Makefile
- main.cc

Compilation and execution instructions:
- Navigate to the folder that contains all the files.
- Use the command `make`, `make all`, or `make a2` to create the object files and compile the files.
- If you would like to delete the object code, use the command `make clean`
- Type the command `./a2` while in the folder in which the executable has been created to interact with the application.
