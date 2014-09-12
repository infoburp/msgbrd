#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <sys/inotify.h>

using namespace std;

int main(int argc, char *argv[]){
  string input;
  string line;
  fstream boardfile;

  boardfile.open("board", ios::in | ios::out | ios::app);

  time_t t = time(0);   // get time now
  struct tm * now = localtime( & t );

  string username = "anon"; //TODO: get username

  boardfile << username
    << " joined on "
    << (now->tm_year + 1900)
    << '-'
    << (now->tm_mon + 1) << '-'
    <<  now->tm_mday
    << endl;

  while (input!="QUIT") {
  boardfile.close();
  boardfile.open("board", ios::in | ios::out | ios::app);
  while ( getline (boardfile,line) ) {
      cout << line << '\n';
  }
  boardfile.close();
  cout << "> ";
  getline(cin, input);
  boardfile.open("board", ios::in | ios::out | ios::app);
  boardfile << "<"<< username << "> " << input << endl;
  boardfile.close();
  }
  return 0;
}
