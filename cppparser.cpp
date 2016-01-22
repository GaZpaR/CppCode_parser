#include <cppparser.h>
#include <string.h>
#include "tree.h"

using namespace std;

int main(int argc, char** argv)
{
  streampos size;
  char * memblock;

	if(argv[1] == NULL){
		cout << "You haven't enter file's name" << endl;
		exit(1);
	}
  ifstream file (argv[1], ios::in | ios::binary | ios::ate);

	cout << "File name is: "<< argv[1] << endl;

  if (file.is_open()) cout << "File is opened" << endl;
  else{
    cout << "Unable to open file" << endl;
    exit(1);
  }

    size = file.tellg();

    memblock = new char [size];

    arbitarytree sometree(argv[1], (uint8_t*)memblock, size);

    uint8_t wut[3]={22,234,7};

    char hui[] = "suuka.h";
    leaf* some = sometree.createLeaf(hui,wut,3);

    file.seekg (0, ios::beg);
    file.read (memblock, size);
    file.close();

    cout << "The entire file content is in memory" << endl;
		cout << "File size is:" << size << " bytes" << endl;
		cout << endl;
		cout << "<File Content>" << endl;
		cout << endl;

		cout << memblock;

		cout << endl;
		cout << "</File Content>" << endl;

    //Here should be dependency resolver

    for(uint32_t i=0; i < size; i++){
      if(memblock[i] == '#'){
        printf("We found #\r\n");
        char condition[7];
        memcpy(condition, &memblock[i+1], 7);
        printf("%s\r\n",condition);
        if(strcmp(condition, "include") == 0) printf("We find include\r\n");
      }
    }

    delete[] memblock;



  return 0;
}
