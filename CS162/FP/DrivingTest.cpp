/*********************************************************************

** Program Filename: DrivingTest.hpp

** Author: Pedro Torres-Picon

** Date: 12/07/2016

** Description: Final Project - Part of a single-player game depicting
the challenge of navigating the DMV. This is the implementation file
for the DrivingTest class, which is derived from the Room class. This
file includes the source code for all the functions in the class.

*********************************************************************/

#include "DrivingTest.hpp"

DrivingTest::DrivingTest(Player* p1) : Room(p1){
  xCoord = 14;
  yCoord = 5;

};

/*********************************************************************

** Description: displayTrack()

** This function uses a loop to display a 2x2 matrix. The switch statement
replaces the numbers 0, 1 and 2 (which is how each different position is
represented in the 2D array) into whatever characters we want to show the
user to represent white/black/ant

*********************************************************************/

void DrivingTest::displayTrack(int track[15][25]) {
  std::cout << "\033[2J\033[1;1H";
  std::cout << "\n           END           " << std::endl;
  for (int x = 0; x < 15; x++) {
    for (int y = 0; y < 25; y++) {
      switch (track[x][y]) {
        case 0:
          std::cout << "#";
          break;
        case 1:
          std::cout << " ";
          break;
        case 2:
          std::cout << "*";
          break;
      }
    }
    std::cout << std::endl;
  }
  std::cout << "   BEGIN                 " << std::endl;
}

Room* DrivingTest::play() {

  std::cout << "Current room: Driving Test Track\n\n" << std::endl;

  if (checkInv("form_57b") && checkInv("form_409h") && checkInv("vision_cert")) {

    bool crashed = false;
    int track[15][25] = { // the test track
      {0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,},
      {0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,},
      {0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,},
      {0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,},
      {0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,},
      {0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,},
      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,},
      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,},
      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,},
      {0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,0,0,0,0,},
      {0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,0,0,0,0,},
      {0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,0,0,0,0,},
      {0,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,},
      {0,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,},
      {0,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,},
    };

    std::cout << "Welcome, please take the driver's seat. Get to the end of the track to pass the test.\n" << std::endl;
    std::cout << "Press any key to begin..." << std::endl;
    system("read");
    displayTrack(track);

    if (!crashed) {

      std::cout << "\n\nYou passed! Great driving. Take this signature to the Forms Department to certify your results." << '\n';
      p->inventory.insert("dtest_signature");
      std::cout << "[dtest_signature added to inventory]\n" << std::endl;

    } else {

      std::cout << "\n\nOh no, you crashed! Practice makes perfect. Come back later and try again." << std::endl;

    }

  } else {

    if (!checkInv("form_57b")){
      std::cout << "Sorry! You can't take the Driving Test without Form 57B. I wouldn't know who you are!\n";
    }
    if (!checkInv("form_409h")){
      std::cout << "Sorry! You can't take the Driving Test without Form 409H. The Written Test needs to be taken before the Driving Test.\n";
    }
    if (!checkInv("vision_cert")){
      std::cout << "Sorry! You can't take the Driving Test without a valid Vision Certificate. That would be dangerous!\n";
    }
    std::cout << "Please come back when you have the proper forms. You can get them in the Forms Department.\n" << std::endl;

  }

  return nextStep();

};
