Name: Fatema Anishbhai Lokhandwala
Student number: 101259465

List of files:
- README.txt: Contains this description
- Channel.h and Channel.cc: Contains information about the Channel such as title and owner. Manages a collection of Videos.
- ChannelList.h and ChannelList.cc: It is a data structure for Channels.
- Client.h and Client.cc: Prints error messages. Downloads copies of Channel and views Videos locally.
- Control.h and Control.cc: Responsible for managing the interactions of other objects. 
- Date.h and Date.cc: Contains information about the date.
- defs.h: Contains preprocessor constants.
- test.cc: Compiles into an executable a2test using the TestControl and Tester classes.
- TestControl.h and TestControl.cc: Responsible for managing the interaction of other objects in order to run tests.
- Tester.h and Tester.cc: Provides functionality for testing.
- Video.h and Video.cc: Contains information about the Video such as title, content and date added.
- VideoList.h and VideoList.cc: It is a data structure for Videos.
- View.h and View.cc: Presents a menu and takes input from the user.
- ViewTube.h and ViewTube.cc: Manages a collection of Channels. Provides functions to add, delete, access, and print Channels and the Videos the Channels manage. Prints error messages.
- Makefile
- main.cc

Compilation and execution instructions:
- Navigate to the folder that contains all the files.
- Use the command "make", "make all", "make a2", or "make a2test" to create the object files and compile the files.
- If you would like to delete the object code, use the command "make clean"
- Type the command "./a2" while in the folder in which the executable has been created to interact with the application from a user’s perspective.
- Type the command "./a2test" while in the folder in which the executable has been created to runs tests.