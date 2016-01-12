#include <cppparser.h>

using namespace std;

int main(int argc, char** argv)
{
  streampos size;
  char * memblock;

  ifstream file (argv[1], ios::in|ios::binary|ios::ate);

	cout << "File's name is: "<< argv[1] << "\r\n";

  if (file.is_open())
  {
    size = file.tellg();
    memblock = new char [size];
    file.seekg (0, ios::beg);
    file.read (memblock, size);
    file.close();

    cout << "the entire file content is in memory\r\n";

		for(uint32_t i=0; i < size; i++)cout << memblock[i];

		cout << "\r\n";

    delete[] memblock;
  }
  else cout << "Unable to open file\r\n";
  return 0;
}
