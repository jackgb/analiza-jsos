#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

class Parser{
  private:
    fstream file;
    string location;
    string content;
    string startSequence = "<tbody>";
    string endSequence = "</tbody>";
  public:
    Parser(){
      choseLocation();
    }

    void choseLocation(){
      cout << "Chose your JSOS file location: ";
      cin >> location;
      openFile();
    }

    void openFile(){
      file.open(location, ios_base::in);
      if(file.is_open()){
        readFile();
      }
      else{
        cout <<"Error, file not found... Please, try again:" << endl;
        choseLocation();
      }
    }

    void readFile(){
      cout << "Opened input file" << endl;
      string file_contents{
        istreambuf_iterator<char>(file),
        istreambuf_iterator<char>()
      };
      content = file_contents;
      parse();
    }

    void parse(){
      size_t start = content.find( startSequence );
      size_t end = content.find( endSequence );
      cout << "start: " << start << " end: " << end << endl;
      fstream output;
      output.open("/home/jacek/output.txt", ios::out|ios::app);
      for(int i = start; i <= end; i++){
        output << content[i];
      }
    }
};

int main(){
  Parser parser;
  return 0;
}
