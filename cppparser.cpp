#include <cppparser.h>
#include <string.h>
#include "graph.h"

using namespace std;

int main(int argc, char** argv)
{
  streampos size;
  char * memblock;

  linklist li;

	if(argv[1] == NULL){
		cout << "You haven't enter file's name" << endl;
		exit(1);
	}
  ifstream file (argv[1], ios::in | ios::binary | ios::ate);

	cout << "File name is: "<< argv[1] << endl;

  if (file.is_open())
  {
    size = file.tellg();
    memblock = new char [size];
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
  }
  else cout << "Unable to open file" << endl;

  #define MESSAGE_LEGTH 50
  newtp l1, l2, l3;

  l1 = (newtp)malloc(MESSAGE_LEGTH*sizeof(newtp));
  l2 = (newtp)malloc(MESSAGE_LEGTH*sizeof(newtp));
  l3 = (newtp)malloc(MESSAGE_LEGTH*sizeof(newtp));

  snprintf(l1, MESSAGE_LEGTH , "Hellow my black bro!\r\n");
  snprintf(l2, MESSAGE_LEGTH , "I would like to see your eyes..\r\n");
  snprintf(l3, MESSAGE_LEGTH , "Fuck'n nigga!\r\n");

  cout << l1 << endl;
  cout << l2 << endl;
  cout << l3 << endl;

  li.push(l1,1);
  li.push(l2,2);
  li.push(l3,3);

  li.view();

  free(l1);
  free(l2);
  free(l3);

  return 0;
}
