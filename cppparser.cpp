#include <cppparser.h>

using namespace std;

int main(int argc, char** argv)
{
  streampos size;
  char * memblock;
	if(argv[1] == NULL){
		cout << "You haven't enter file's name" << endl;
		exit(1);
	}
  ifstream file (argv[1], ios::in|ios::binary|ios::ate);

	cout << "File name is: "<< argv[1] << "\r\n";

  if (file.is_open())
  {
    size = file.tellg();
    memblock = new char [size];
    file.seekg (0, ios::beg);
    file.read (memblock, size);
    file.close();

    cout << "The entire file content is in memory\r\n";
		cout << "File size is:" << size << " bytes" << endl;
		cout << "\r\n";
		cout << "<File Content>" << endl;
		cout << endl;

		cout << memblock;
		//for(uint32_t i=0; i < size; i++)cout << memblock[i];

		cout << endl;
		cout << "</File Content>" << endl;

    delete[] memblock;
  }
  else cout << "Unable to open file\r\n";
  return 0;
}
