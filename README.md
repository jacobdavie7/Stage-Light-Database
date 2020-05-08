### Background
This is a program that is a database for (stage) lights. One of my hobbies is live A/V. I particularly enjoy lighting. I have worked on lighting stuff in quite a few venues. I particularly enjoy doing at DSU for CRU. I even bought a fair amount of my own equipment for lighting at CRU. ******* and myself really overhauled all the production this year for it. I had actually been wanting a database like I built for myself. Because Cru is what was freshest in my mind, it is what I modeled it after. I have two files with real data from the lighting in the TC underground (*cruLights1.txt* and *cruLights2.txt*). I also have a file of just random test data (*testdata.txt*).

### More Background, future plans, and versions
This is something that I actually plan to use and expand upon. I really want to get it working with linked lists. You can see the progress I made with it in the *workInProgress.c* file. I pushed though so many problems, but I was having some major ones and not anywhere close enough to getting it done with too little time, so I moved over and made it using arrays rather than a linked list. That is the version that works and should be graded for my midterm. It is calle *workingArrayVersion.c*. 

### Header File Explination
I also have two header files (one that gets called, two different versions of it). The one that gets called is *dip3.h*. It will need to be compiled before my program will work. The header file calls in my final project from 150 as it relates to my current one. Old stage lights have what are called dip switches on them to control what channel you control them on. They are so old, that when I saw DSU had lights with dip switches, I discovered that the app I used for calculations no longer worked with the OS version of my phone. So, I made my own. The *dip3.h* program allows you to enter a 1 or 0 for each switch (on or off) and it will draw out how the switches should be set. It helps troubleshooting. I have a ton I want to improve upon in the dip program, so *dip2.h* is what was going to be my updated version. I got most of it to work, I was just having some problems with changing what spot in the 2d array to overwrite because you don't just move from one to the next spot. I have a few ideas to try later. 

### How to Run Program
So, to run my program, after you compile it and the header file and you have a txt file with data, you can enter **./a.out NAMEOFDATAFILE.txt** to run it

### Root Menu, Edit Database Menu, and Adding a light
In the first menu, you will see five options, option 1 is to edit the database, you will be given two options, to add a light to edit a light. If you add a light, it will go through and ask you all the pieces of information needed and store it in the database as well as assign it a randomly generated id number. One of the future projects is to make sure it can not generate a number that already exists in the database. 

### Editing a Light 1
If you choose to edit a light rather than add one, it will ask you if you want to print out the database so you can see the ID numbers. If you type y, then it will print them and take you back to the option for adding or editing a light. You can then go back into edit and hit any other key to continue. It is another thing I want to make better, if you print the database there, to just keep continuing. 

### More Editing a Light
Once you are past the printing the database, it will ask you to enter the ID number of the light you want to edit. You can then choose what you want to change. You can change everything but the ID number. If you don't want to change the name (string), it will ask what you want the new value to be then depending on what thing you wanted to change, it will copy that value to the database. If it is a string, then it will do the same thing, just a little differently. If you choose to change the mode, it will also print them out, just like when adding a light.

### Printing and Exporting
Back to the root menu, if you choose to print, it will just print the database to the terminal. If you choose export, it will export the current database into two files. The first is a nice looking file, it looks just like what gets printed to the screen. The other file is not easy to read, and you need to know what all the numbers mean, but it is in the format that can be read in by the program, so if you wanted to run the program again with your updated database, you would feed it that one. 

### Rest of Root Menu
The next option runs the *dip3.h* header file. 

The last option is titled quit. I am guessing that you can guess what it does.
