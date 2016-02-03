#include <cppparser.h>
#include <string.h>
#include "tree.h"

using namespace std;

size_t calcNameLength(char *file)
{
  size_t len = 0;
  cout << "File is:" << file << endl;
  while(1){
    if(*file == '\"' || *file == '<') break;
    file++;
  }
  
  file++;
    while(1){
        
     	if(file[len] == '\"' || file[len] == '>') break;
	len++;
    }
  
  
  return len;
}

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

    file.seekg (0, ios::beg);
    file.read (memblock, size);
    file.close();

    arbitarytree sometree(argv[1], (uint8_t*)memblock, size);

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
        if(strncmp(&memblock[i], "#include",8) == 0){
	  cout << "We find #include" << endl;

	  size_t namelen = calcNameLength(&memblock[i+8]);
	  cout << "Name length is:" << namelen << endl;
	  char *filename = new char[256];
	  snprintf(filename, namelen+1,"%s",(char*)&memblock[i+10]);
	  
	  //ifstream file (filename, ios::in | ios::binary | ios::ate);
	  ifstream file(filename, ios::in | ios::binary | ios::ate);
	  cout << "File name is: "<< filename << endl;

	  if (file.is_open()) cout << "File is opened" << endl;
	  else{
	    char *p1name = new char[1024];
	    snprintf(p1name, 1024, "/user/include/c++/5.3.1/%s",filename);
	    ifstream file (filename, ios::in | ios::binary | ios::ate);
	    if (file.is_open()) cout << "File is opened" << endl;
	    else{
	      snprintf(p1name, 1024, "/user/local/include/%s",filename);
	      ifstream file (filename, ios::in | ios::binary | ios::ate);
	      if (file.is_open()) cout << "File is opened" << endl;
	    } 
	    cout << "Unable to open file" << endl;
	    exit(1);
	  }
	  
	  streampos length = file.tellg();
	  char *filecontent = new char[length+1];

	  file.seekg (0, ios::beg);
	  file.read(filecontent, length);
	  file.close();		 
	  sometree.addLeaf(argv[1], filename,(uint8_t*)filecontent, length );
	}
	
	if(strncmp(&memblock[i], "#define",7) == 0) cout << "We find #include" << endl;

      }
    }

    delete[] memblock;



  return 0;
}
