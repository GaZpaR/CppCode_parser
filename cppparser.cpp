#include <cppparser.h>
#include <string.h>
#include "tree.h"

using namespace std;

void printfilename(char *file)
{
  size_t len = 0;
  
  while(1){
    if(*file == '\"' || *file == '<') break;
    file++;
  }
  
  file++;
    while(1){
        
     	if(file[len] == '\"' || file[len] == '>') break;
	len++;
    }
    char *temp = new char[len+1];
    snprintf(temp, len+1,"%s",file);
    
    printf("Included file name is: %s\r\n",temp);

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
    //cout << memblock;
    cout << endl;
    cout << "</File Content>" << endl;

    //Here should be dependency resolver
  char *current_catalog = new char[1024*2];
  size_t cc_pathlen;
  current_catalog = getcwd(current_catalog, cc_pathlen);
  cout << "Path to curent catalog is:" << endl << current_catalog << endl;
  cout << "Path length is: " << cc_pathlen << endl;
  DIR *dir;
  dir = opendir(current_catalog);
  struct dirent *entry;
  uint32_t num = 0;
  while((entry = readdir(dir)) != NULL){
    cout << "File " << num << " is:\"" << entry->d_name << "\"" << endl;
    num++;
  }

  closedir(dir);

  ifstream dotfile("..", ios::in | ios::binary | ios::ate);
  if(dotfile.is_open()){
    
    cout << "Dot file is  opened" << endl;
    int dsize = dotfile.tellg();
    
    cout << "Dot file length is: " << dsize << endl;

    if(dsize > 0){
      char *dotf = new char[dsize];
      dotfile.seekg (0, ios::beg);
      dotfile.read (dotf, dsize);
      dotfile.close();

      cout << "Dot file content is:"<< endl << dotf << endl;

      delete[] dotf;
    }

  }
  else cout << "Can't open dot file" << endl;

  dotfile.close();

    for(uint32_t i=0; i < size; i++){
      if(memblock[i] == '#'){
        if(strncmp(&memblock[i], "#include",8) == 0){
	  cout << "We find #include" << endl;

	  printfilename(&memblock[i]);
	  
	}
	
	if(strncmp(&memblock[i], "#define",7) == 0) cout << "We find #define" << endl;

      }
    }

    delete[] memblock;



  return 0;
}
