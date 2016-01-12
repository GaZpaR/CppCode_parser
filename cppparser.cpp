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

    delete[] memblock;
  }
  else cout << "Unable to open file" << endl;
  return 0;
}
