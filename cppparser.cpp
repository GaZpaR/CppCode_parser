#include <cppparser.h>
#include <string.h>
#include <vector>
#include "tree.h"

#define Suka 200

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

bool ifinclusion(char *ptr){
  if(strncmp(ptr, "#include",8) == 0){
     return true;
  }
  return false;
}

bool ifmacro(char *ptr){
  if(strncmp(ptr, "#define", 7) == 0){
    return true;
  }
  return false;
}

void parseLines(char *ptr, vector<string> *vec, size_t size)
{
  size_t linelen = 0;
  for(size_t i=0; i < size; i++){
    linelen++;
    if(ptr[i] == '\n'){
      char *line = new char[linelen];
      memcpy(line, &ptr[i-linelen], linelen);
      vec->push_back(line);
      memset(line, 0x00, linelen);
      delete[] line;
      linelen = 0;
    }
  }
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

	cout << "MM: "<< Suka << endl;

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


  vector<string> doclines;
  parseLines(memblock, &doclines, size);

  size_t ql = doclines.size();
  cout << "Lines quantity is: " << ql << endl;
  
  for(uint32_t i=1; i < ql; i++){
    cout << "Line: "<< i << "; size : "<< doclines[i].length() << "; content:"<< doclines[i]<<endl ;

  }
  
    for(uint32_t i=0; i < size; i++){
      if(ifinclusion(&memblock[i])) cout << "We find inclusion"<< endl;
      if(ifmacro(&memblock[i])) cout << "We find define"<< endl;
    }
    

    delete[] memblock;



  return 0;
}
