#include <cppparser.h>
#include <string.h>

using namespace std;

typedef char* newtp;
struct node
{
    newtp data; //  Data
    node* next; // Pointer to the next element
    node* pred; // Pointer to the previous element
};

class linklist // Link list class
{
private:
    node* first; // Pointer to the begin
public:
    linklist() { first = NULL; } // Init linklist
                                 // where is no usefull info

    void push( newtp d, int pos); // Adding elemant method
    newtp pop( int pos);  // Deleting element method
    void clean(); // Clean link list
    void view(); // Print list content to display
};

void linklist::push( newtp d, int pos) // Adding elemant method
{

    node* newnode = new node; // Creating new element
    newnode->data = d; // filling element with new data
    if(first == NULL)   // If it first element in the list
    {
        newnode->next = newnode;
        newnode->pred = newnode;
        first = newnode; // first  point to it
    }
    else
    {
        node* temp = first; // Creating current pointer
        for ( int i = pos; i > 1; i--,temp=temp->next); // Cycle
            temp->pred->next = newnode;
            newnode->pred = temp->pred;
            newnode->next = temp; // Adding before current pointer
            temp->pred = newnode;
    }
}

newtp linklist::pop( int pos) // Deleting element method by index
{
  if(first == NULL)  return 0; // If list is NULL
  newtp val;
  if(first == first ->next) // If it is last element in the list
  {
      val = first->data;
      delete first;
      first = NULL;
  }
  else
 {
      node* temp = first;
      for ( int i = pos; i > 1; i--, temp = temp->next);
          if( temp == first) first = temp->next;
              temp->pred->next = temp->next; // Deleting temporary element
              temp->next->pred = temp->pred;
              val = temp->data;
              delete temp;
  }
  return val;
}

void linklist::clean() // Clear list
{
    if(first == NULL) return ;
    for ( node* newnode = first->next; newnode!=first; newnode = newnode->next) delete newnode;
    delete first;
    first = NULL;
}

void linklist::view() // View elements in the list
{
    if(first == NULL) return ;
    node* newnode = first;
    do
    {
        cout << newnode->data << endl;
        newnode = newnode->next;
    } while(newnode!=first);
}

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
