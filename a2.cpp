#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

class Nucleotide{
  private:
    char base;
    Nucleotide* p_next_nucleotide;
    Nucleotide* p_prev_nucleotide;

  public:
    Nucleotide();
    Nucleotide(char c_in);
    char get_nucleotide();
    void set_nucleotide(char);
    Nucleotide* get_next_nucleotide();
    Nucleotide* get_prev_nucleotide();
    void set_next_nucleotide(Nucleotide* p_next_in);
    void set_prev_nucleotide(Nucleotide* p_next_in);


};
class DNAsequence{
  private:
      string filename;
      Nucleotide* p_head_nucleotide;
      DNAsequence* p_next_DNAsequence;
      DNAsequence* p_prev_DNAsequence;
      Nucleotide* p_tail_nucleotide;
  public:
    DNAsequence();
    DNAsequence(string);
    string getfilename();
    Nucleotide* get_Nucleotide_head();
    void set_Next_DNAsequence(DNAsequence*);
    void set_prev_DNAsequence(DNAsequence*);
    DNAsequence* get_next_DNAsequence();
    DNAsequence* get_prev_DNAsequence();
    void delete_DNA_sequence();
    char pop_nucleotide();
    void add_nucleotide(char);
    void add_nucleotide_front(char);
    void Find_DNA_sequence_by_input();
    void Find_DNA_sequence_by_file();
    void Add_DNA_sequence_by_input();
    void Add_DNA_sequence_by_file();
    void Delete_DNA_sequence_by_input();
    void Replace_DNA_sequence_by_input();
    // void Replace_DNA_sequence_by_file();
    // void Save_edited_DNA_sequence();
    friend ostream& operator <<(ostream& os, const DNAsequence& DNAseq);
    // ~DNAsequence();
};
class DNADatabase: public DNAsequence{
  private:
    DNAsequence* p_head_DNAsequence;
  public:
    DNADatabase();
    void addfile(string);
    void printnames();
    void Analyse_the_DNA_database();
    string choosefile(int);
    string deque_DNAsequence();
    void pop_DNAsequence();
    int size_of_database();
    DNAsequence* get_p_head_DNAsequence();
    DNAsequence* getfilepointer(int choice2);
    // ~DNADatabase();
    friend ostream& operator <<(ostream& os, const DNADatabase& DNAdtb);
};
void enter_file_name(DNADatabase*);


int main(){
  DNADatabase dna_db;
  int choice=0;
  bool repeat=true;
  while(repeat){
    while(choice!=1 && choice!=2 && choice!=3 && choice!=4){ // && !(cin>>choice)
      cout << endl << "Welcome to the DNA Edititng program" << endl;
      cout << "Select an option:" << endl;
      cout << "(1) Load DNA(s)." << endl;
      cout << "(2) Process a DNA." << endl;
      cout << "(3) Analyse the DNA database" << endl;
      cout << "(4) Quit." << endl;
      cout << ">";
      cin >> choice;
      if (cin.fail())
      {
         cin.clear();
         cin.ignore(500, '\n');
      }
    }

    if(choice==1){
      cout << "Enter the DNA file names:" << endl;
      cout << "For multiple files, separate them by a comma. Only .fna are recognised" << endl;
      enter_file_name(&dna_db);
    }

    else if (choice==2){
      cout << "SIZE OF DATABASE:  " <<  dna_db.size_of_database() << endl;
      bool repeat=true;
      int choice2;
      int choice3=0;
      while(choice3!=9){
        while(repeat){
          cout << "Select a DNA to process:" << endl;
          cout << "dna_db:     " << endl;
          cout << dna_db << endl;
          cout << "dna db print names fucntion:  " << endl;
          //dna_db.printnames();
          cout << ">";
          cin >> choice2;

          if(choice2<=dna_db.size_of_database()){
            repeat=false;
          }
        }
        string file_choice_2=dna_db.choosefile(choice2);
        cout << endl<< "file choice:  " << file_choice_2 << endl;
        DNAsequence* file_pointer=dna_db.getfilepointer(choice2); //returns pointer that points to the DNA sequence file we will be analysing
        DNAsequence new_file = *file_pointer;
          cout << endl;
          cout << "Select from one of the following options" << endl;
          cout << "1. Find DNA sequence by input" << endl;
          cout << "2. Find DNA sequence by file" << endl;
          cout << "3. Add DNA sequence by input" << endl;
          cout << "4. Add DNA sequence by file" << endl;
          cout << "5. Delete DNA sequence by input" << endl;
          cout << "6. Replace DNA sequence by input" << endl;
          cout << "7. Replace DNA sequence by file" << endl;
          cout << "8. Save edited DNA sequence" << endl;
          cout << "9. Exit submenu" << endl;
          cout << ">";
          cin >> choice3;
          if (choice3==1){
            cout << *file_pointer << endl;
            new_file.Find_DNA_sequence_by_input();
          }
          else if (choice3==2){
            new_file.Find_DNA_sequence_by_file();
          }
          else if (choice3==3){
            new_file.Add_DNA_sequence_by_input();
            cout << file_pointer << endl;
          }
          else if (choice3==4){
            new_file.Add_DNA_sequence_by_file();
          }
          else if (choice3==5){
            new_file.Delete_DNA_sequence_by_input();
          }
          else if (choice3==6){
            new_file.Replace_DNA_sequence_by_input();
          }
          else if (choice3==7){
            void Replace_DNA_sequence_by_file();
          }
          else if (choice3==8){
            void Save_edited_DNA_sequence();
          }
        }
      //  in.close();           //closes the input file
      }

    else if (choice==3){
      dna_db.Analyse_the_DNA_database();
    }
    else if (choice==4){
      repeat=false;
    }
    choice=0;
  }
  return 0;
}

void enter_file_name(DNADatabase *dna_db){
  string filename;
  cout << ">";
  cin.ignore(); //clearing cin
  getline(cin,filename); //getting all inputs from user input, including white space
  vector<string> v; //initialising vector to hold file names
  char delimiter = ','; //setting a delimiter which will split the input by commas
  int stringstart=0; //initialising int to represent where we will start each individual name from
  for (int i=0; i<filename.size(); i++){
    if (filename[i]==delimiter){
      v.push_back(filename.substr(stringstart,i-stringstart)); //for the whole input, every time the loop encounters a comma it will store the input between that comma and thr previous comma
      stringstart=i+1; // sets a new start for the next part of the input that will be stored after the previous comma
    }
  }
  v.push_back(filename.substr(stringstart,filename.size()-stringstart)); // stores the last string of the input when there isnt a comma to end the string
  DNAsequence* file_pointer;  //pointer to the file in database linked list that we will be filling with data
  bool first = true;    //bool vlaue for the first line of the file, which we want to ignore as it only holds descriptors and not nucleotide data
  for(int i=0; i<v.size(); i++){
    bool valid = true;
    v[i].erase(remove(v[i].begin(), v[i].end(), ' '), v[i].end()); //for every name that has been entered we will remove the white space
    if (v[i].size() < 5){
      v.erase(v.begin()+i); //if file entered is less than 5 characters long it will be ignored as it cannot have a .fda at the end of the name
      i--;
      valid=false;
    } else if (v[i].substr(v[i].size()-4,4)!=".fna"){ //checks if last 4 characters in the entry are .fna
      v.erase(v.begin()+i); //if extension != fna the entry will be ignored
      i--;
      valid=false;
    }
    if (valid==true){
      string tempstring;
      tempstring=v[i];
      dna_db->addfile(tempstring); //if the name is in the proper .fna format it will be added to the database
      cout << "dna_db:     " << dna_db << endl;
      cout << "tempstring"  << tempstring << endl;

      fstream in;             //used to open the file
      in.open(tempstring, fstream::in);   //opens the file that we entered into the program prviously and names the data stream that we will be getting data from "in"
      if (in.fail())          //checks to see if the file has failed to open
      {
        cout << "Input file opening failed.\n";   //if file failed to open the program will output this
      }
      else{
        cout << "give the file a second to load... " << endl;
        if (first){ //if its the first file being opened, the head of the list of files gets set to the first input
          file_pointer=dna_db->get_p_head_DNAsequence();
          first = false;
        }
        cout << file_pointer << endl;
        char nucleotide;
        while(!in.eof()){ //the first line of a .fna file is a descriptor line, hence this while loop gets the first line but does not store it anywhere
          nucleotide=in.get();
          if (nucleotide=='\n')
          break;
        }
        while(!in.eof()){   //gets each nucleotide from the rest of the file and enters it into a new DNAsequence
          nucleotide=in.get();
          if (nucleotide!='\n' && !in.eof()){
            file_pointer->add_nucleotide(nucleotide);
            cout << nucleotide;
          }
        }
        cout << endl;
        file_pointer=file_pointer->get_next_DNAsequence();
      }
    }
  }
}

// NUCLEOTIDE FUNCTIONS
Nucleotide::Nucleotide(){
  base = 'A';
  p_next_nucleotide=nullptr;
  // p_prev_nucleotide=;
}
Nucleotide::Nucleotide(char c_in){
  base = c_in;
  p_next_nucleotide=nullptr;
}
char Nucleotide::get_nucleotide(){
  return base;
}
void Nucleotide::set_nucleotide(char base_in){
  base=base_in;
}
Nucleotide* Nucleotide::get_next_nucleotide(){
  return p_next_nucleotide;
}
Nucleotide* Nucleotide::get_prev_nucleotide(){
  return p_prev_nucleotide;
}
void Nucleotide::set_next_nucleotide(Nucleotide* p_next_in){
  p_next_nucleotide=p_next_in;
}
void Nucleotide::set_prev_nucleotide(Nucleotide* p_prev_in){
  p_prev_nucleotide=p_prev_in;
}


//DNASEQUENCE FUNCTIONS
DNAsequence::DNAsequence(){
  filename="filename";
  p_head_nucleotide=nullptr;
  p_next_DNAsequence = nullptr;
  // p_prev_DNAsequence=p_head_DNAsequence;
  p_tail_nucleotide=nullptr;
}
DNAsequence::DNAsequence(string filename_in){
  filename=filename_in;
  p_next_DNAsequence = nullptr;
}
string DNAsequence::getfilename(){
  return filename;
}
void DNAsequence::set_Next_DNAsequence(DNAsequence* p_next_in){
  p_next_DNAsequence=p_next_in;
}
void DNAsequence::set_prev_DNAsequence(DNAsequence* p_prev_in){
  p_prev_DNAsequence=p_prev_in;
}
DNAsequence* DNAsequence::get_next_DNAsequence(){
    return p_next_DNAsequence;
}
DNAsequence* DNAsequence::get_prev_DNAsequence(){
    return p_prev_DNAsequence;
}
Nucleotide* DNAsequence::get_Nucleotide_head(){
  return p_head_nucleotide;
}
void DNAsequence::add_nucleotide(char nucleotide_in){
  // Nucleotide* p_temp=p_head_nucleotide;
  if (p_head_nucleotide==nullptr){
    p_head_nucleotide= new Nucleotide(nucleotide_in);
    p_tail_nucleotide = p_head_nucleotide;
    return;
  }
  Nucleotide* new_nucleotide= new Nucleotide(nucleotide_in);
  p_tail_nucleotide->set_next_nucleotide(new_nucleotide);
  new_nucleotide->set_prev_nucleotide(p_tail_nucleotide);
  p_tail_nucleotide = new_nucleotide;
}
void DNAsequence::add_nucleotide_front(char nucleotide_in){
  // Nucleotide* p_temp=p_head_nucleotide;
  if(p_head_nucleotide==nullptr){
    p_head_nucleotide= new Nucleotide(nucleotide_in);
    p_tail_nucleotide = p_head_nucleotide;
    return;
  }
  Nucleotide* new_nucleotide= new Nucleotide(nucleotide_in);
  p_head_nucleotide->set_prev_nucleotide(new_nucleotide);
  new_nucleotide->set_next_nucleotide(p_head_nucleotide);
  p_head_nucleotide= new_nucleotide;
}
// void DNAsequence::delete_DNA_sequence(){
//
// }
void DNAsequence::Find_DNA_sequence_by_input(){
  string input;
  // cout << p_head_nucleotide << endl;
  Nucleotide* p_seek_file= p_head_nucleotide;
  DNAsequence input_DNAsequence;    //defines new dna sequence linked list to hold inputted sequence
  int start_index=1;    //start and end index keep tract of where the matched sequence lies in the file
  int end_index=0;
  Nucleotide* p_print_10_temp; //defines new pointer to a nucleotide that we will use to print 10 bases before and after match

  cout << "Enter a nucleotide sequence that you would like to look for in the specified file:" << endl;
  cout << ">";
  cin >> input;
  char DNAsequencearr[input.length()];            //creates an array of the same size as our inout that we will use to load the contents of our input into its own linked list to compare with the file we want
  for (int i=0; i<input.length(); i++){   //loads contents of string into array
    DNAsequencearr[i]=input[i];
    input_DNAsequence.add_nucleotide(DNAsequencearr[i]);    //adds nucleotide to
  }
  Nucleotide* p_seek_input= input_DNAsequence.get_Nucleotide_head();
  bool match=false; //lets user know if a match has been found
  int counter;
  while(p_seek_file!=nullptr){
    start_index++;
    p_seek_input= input_DNAsequence.get_Nucleotide_head();
    if (p_seek_file->get_nucleotide()==p_seek_input->get_nucleotide()){
      p_print_10_temp=p_seek_file; //sets print_10 pointer to the first nucleotide in the matched sequence
      for(counter=1; counter<input.length(); counter++){
        p_seek_file=p_seek_file->get_next_nucleotide();
        p_seek_input=p_seek_input->get_next_nucleotide();
        if(p_seek_file->get_nucleotide()!=p_seek_input->get_nucleotide()){
          break;
        }
      }
      // cout << "counter:  " << counter << endl;
      // cout << "input.length():  " << input.length() << endl;
      if (counter==input.length()){
        match=true;
        end_index=start_index+input.length()-1;
        DNAsequence ten_bases_before;
        DNAsequence ten_bases_after;
        cout << "you found a match!" << endl;
        cout << "First base pair position: " << start_index << endl;
        cout << "Last base pair position: " << end_index << endl;
        cout << "base pair length: " << input.length() << endl;
        cout << "10 base pairs preceding the sequence: ";
        //obtaining 10 previous base pairs
        for (int i=0; i<10; i++ ){
          if(p_print_10_temp->get_prev_nucleotide()!=nullptr){
            p_print_10_temp=p_print_10_temp->get_prev_nucleotide();
            ten_bases_before.add_nucleotide_front(p_print_10_temp->get_nucleotide());
          }
        }
        cout << ten_bases_before << endl;
        cout << "Matched sequence:  " << input_DNAsequence << endl;
        cout << "10 base pairs following matched sequence:  ";
        // obtaining 10 following base pairs
        p_print_10_temp=p_seek_file; //sets print_10 pointer to the last nucleotide that was matched
        for (int i=0; i<10; i++ ){
          if(p_print_10_temp->get_next_nucleotide()!=nullptr){
            p_print_10_temp=p_print_10_temp->get_next_nucleotide();
            ten_bases_after.add_nucleotide(p_print_10_temp->get_nucleotide());
          }
        }
        cout << ten_bases_after;
        start_index=end_index;
      }
    }
    p_seek_file=p_seek_file->get_next_nucleotide();
  }
  if (match==false)
  cout << "no match was found" << endl;
}
void DNAsequence::Find_DNA_sequence_by_file(){
  string tempstring;
  Nucleotide* p_seek_file= p_head_nucleotide; //defines pointer that iterates through file we are looking at
  Nucleotide* p_seek_input; //defines pointer that iterates through the input file
  bool first = true;    //bool vlaue for the first line of the file, which we want to ignore as it only holds descriptors and not nucleotide data
  DNAsequence input_DNAsequence;    //defines new dna sequence linked list to hold inputted file
  int length_input_DNAsequence=0;
  int start_index=1;    //start and end index keep tract of where the matched sequence lies in the file
  int end_index=0;
  Nucleotide* p_print_10_temp; //defines new pointer to a nucleotide that we will use to print 10 bases before and after match

  cout << "Enter a file that you would like to look for in the specified file:" << endl;
  cout << ">";
  cin >> tempstring;

  fstream in;             //used to open the file
  in.open(tempstring, fstream::in);   //opens the file that we entered into the program and names the data stream that we will be getting data from "in"
  if (in.fail())          //checks to see if the file has failed to open
  {
    cout << "Input file opening failed.\n";   //if file failed to open the program will output this
  }
  else{
    cout << "give the file a second to load... " << endl;
    char nucleotide;
    while(!in.eof()){ //the first line of a .fna file is a descriptor line, hence this while loop gets the first line but does not store it anywhere
      nucleotide=in.get();
      if (nucleotide=='\n')
      break;
    }
    while(!in.eof()){   //gets each nucleotide from the rest of the file and enters it into a new DNAsequence
      nucleotide=in.get();
      if (nucleotide!='\n'){
        input_DNAsequence.add_nucleotide(nucleotide);
        length_input_DNAsequence++;
      }
    }
  }

  p_seek_input= input_DNAsequence.get_Nucleotide_head();
  int counter;
  while(p_seek_file!=nullptr){
    start_index++;
    p_seek_input= input_DNAsequence.get_Nucleotide_head();
    if (p_seek_file->get_nucleotide()==p_seek_input->get_nucleotide()){
        p_print_10_temp=p_seek_file; //sets print_10 pointer to the first nucleotide in the matched sequence
      for(counter=1; counter<length_input_DNAsequence; counter++){
        p_seek_file=p_seek_file->get_next_nucleotide();
        p_seek_input=p_seek_input->get_next_nucleotide();
        if(p_seek_file->get_nucleotide()!=p_seek_input->get_nucleotide()){
          break;
        }
      }
      // cout << "counter:  " << counter << endl;
      // cout << "input.length():  " << input.length() << endl;
      if (counter==length_input_DNAsequence){
        end_index=start_index+length_input_DNAsequence-1;
        DNAsequence ten_bases_before;
        DNAsequence ten_bases_after;
        cout << "you found a match!" << endl;
        cout << "First base pair position: " << start_index << endl;
        cout << "Last base pair position: " << end_index << endl;
        cout << "base pair length: " << length_input_DNAsequence << endl;
        cout << "10 base pairs preceding the sequence: ";
        //obtaining 10 previous base pairs
        for (int i=0; i<10; i++ ){
          if(p_print_10_temp->get_prev_nucleotide()!=nullptr){
            p_print_10_temp=p_print_10_temp->get_prev_nucleotide();
            ten_bases_before.add_nucleotide_front(p_print_10_temp->get_nucleotide());
          }
        }
        cout << ten_bases_before << endl;
        cout << "Matched sequence:  " << input_DNAsequence << endl;
        cout << "10 base pairs following matched sequence:  ";
        // obtaining 10 following base pairs
        p_print_10_temp=p_seek_file; //sets print_10 pointer to the last nucleotide that was matched
        for (int i=0; i<10; i++ ){
          if(p_print_10_temp->get_next_nucleotide()!=nullptr){
            p_print_10_temp=p_print_10_temp->get_next_nucleotide();
            ten_bases_after.add_nucleotide(p_print_10_temp->get_nucleotide());
          }
        }
        cout << ten_bases_after;
        start_index=end_index;
      }
    }
    p_seek_file=p_seek_file->get_next_nucleotide();
  }
}
void DNAsequence::Add_DNA_sequence_by_input(){
  string input;
  int base_position;
  Nucleotide* p_seek_file= p_head_nucleotide; //defines pointer that iterates through file we are looking at as the head pointer of
  cout << "Enter a nucleotide sequence that you would like to enter to the file: " << endl;
  cout << ">";
  cin >> input;
  Nucleotide* head = new Nucleotide(input[0]); //defines a pointer that holds the first nucleotide in the inputed sequence
  Nucleotide* tail = head; //defines a pointer that holds the last nucleotide int he inputted sequence. At first, since there is only one nucleotide in the inputted sequence, it will be equal to the first nucleotide

  for (int i=1; i<input.length(); i++){
    Nucleotide* new_nuc = new Nucleotide(input[i]);   //loads contents of string into array
    tail->set_next_nucleotide(new_nuc); //adds next inputted nucleotide to the end of the linked list
    new_nuc->set_prev_nucleotide(tail); //sets the previous nucleotide of the new tail to the previous tail
    tail = new_nuc; //sets tail pointer to the new tail
    // input_DNAsequence.add_nucleotide(DNAsequencearr[i]);    //adds nucleotide to
  }

  cout << "Enter the base pair you would like to enter your sequence at: " << endl;
  cout << ">" << endl;
  cin >> base_position;
  for (int i=0; i<base_position; i++){  //finds pointer that points to where we want to insert new sequence
    p_seek_file=p_seek_file->get_next_nucleotide();
  }
  Nucleotide* start = p_seek_file->get_prev_nucleotide(); //start is the nucleotide before the position where we want to insert
  if (start != nullptr){
    start->set_next_nucleotide(head); //sets the nucelotide after start to the first nucleotide in the inputted sequence
  } else {
    p_head_nucleotide = head; //if inserting at the start if the file we are editing, the first nucleotide of the inputted sequence becomes the start of the file
  }

  head->set_prev_nucleotide(start);
  tail->set_next_nucleotide(p_seek_file);
  if (p_seek_file != nullptr){
    p_seek_file->set_prev_nucleotide(tail);
  } else {
    p_tail_nucleotide = tail;
  }

  for (Nucleotide* p_seek=p_head_nucleotide; p_seek!=nullptr ; p_seek=p_seek->get_next_nucleotide()){
    cout << p_seek->get_nucleotide();
  }
  cout << endl;
}
void DNAsequence::Add_DNA_sequence_by_file(){
  string tempstring;
  int base_position;
  Nucleotide* p_seek_file= p_head_nucleotide; //defines pointer that iterates through file we are looking at, starting with the first one
  Nucleotide* head=nullptr; //defines pointer which refers to the first nucleotide in input file
  Nucleotide* tail=nullptr; //defines pointer which refers to the last nucleotide in input file

  cout << "Enter a file that you would like to insert into the specified file:" << endl;
  cout << ">";
  cin >> tempstring;

  fstream in;             //used to open the file
  in.open(tempstring, fstream::in);   //opens the file that we entered into the program and names the data stream that we will be getting data from "in"
  if (in.fail())          //checks to see if the file has failed to open
  {
    cout << "Input file opening failed.\n";   //if file failed to open the program will output this
  }
  else{
    cout << "give the file a second to load... " << endl;
    char nucleotide;
    while(!in.eof()){ //the first line of a .fna file is a descriptor line, hence this while loop gets the first line but does not store it anywhere
      nucleotide=in.get();
      if (nucleotide=='\n')
      break;
    }
    while(!in.eof()){   //gets each nucleotide from the rest of the file and enters it into a new DNAsequence
      nucleotide=in.get();
      Nucleotide* new_nuc = new Nucleotide(nucleotide);
      if (nucleotide!='\n'){
        if(head==nullptr){
          head=new_nuc;
          tail=head;
        }
        else {
          tail->set_next_nucleotide(new_nuc);
          new_nuc->set_prev_nucleotide(tail);
          tail=new_nuc;
        }
      }
    }
  }

  cout << "Enter the base pair you would like to enter your sequence at: " << endl;
  cout << ">" << endl;
  cin >> base_position;
  for (int i=0; i<base_position; i++){  //finds pointer that points to where we want to insert new sequence
    p_seek_file=p_seek_file->get_next_nucleotide();
  }
  Nucleotide* start = p_seek_file->get_prev_nucleotide(); //start is the nucleotide before the position where we want to insert
  if (start != nullptr){
    start->set_next_nucleotide(head); //sets the nucelotide after start to the first nucleotide in the inputted sequence
  } else {
    p_head_nucleotide = head; //if inserting at the start if the file we are editing, the first nucleotide of the inputted sequence becomes the start of the file
  }

  head->set_prev_nucleotide(start);
  tail->set_next_nucleotide(p_seek_file);
  if (p_seek_file != nullptr){
    p_seek_file->set_prev_nucleotide(tail);
  } else {
    p_tail_nucleotide = tail;
  }

  for (Nucleotide* p_seek=p_head_nucleotide; p_seek!=nullptr ; p_seek=p_seek->get_next_nucleotide()){
    cout << p_seek->get_nucleotide();
  }
  cout << endl;
}
void DNAsequence::Delete_DNA_sequence_by_input(){
  int base_position;
  int base_length;
  Nucleotide* p_seek=p_head_nucleotide;
  Nucleotide* p_before_deletion;
  Nucleotide* p_after_deletion;
  cout << "Enter a base pair position:" << endl;
  cout << ">";
  cin >> base_position;
  cout << endl << "Enter a base pair length to delete:" << endl;
  cout << ">";
  cin >> base_length;
  for (int i=1; i<base_position;i++){
    p_seek=p_seek->get_next_nucleotide();
  }
  p_before_deletion=p_seek;
  for (int i=0; i<base_length; i++){
    p_seek=p_seek->get_next_nucleotide();
  }
  p_after_deletion=p_seek->get_next_nucleotide();
  p_before_deletion->set_next_nucleotide(p_after_deletion);
  p_after_deletion->set_prev_nucleotide(p_before_deletion);

  for (Nucleotide* p_seek=p_head_nucleotide; p_seek!=nullptr ; p_seek=p_seek->get_next_nucleotide()){
    cout << p_seek->get_nucleotide();
  }
}
void DNAsequence::Replace_DNA_sequence_by_input(){
  int base_position;
  int base_length;
  string tempstring;
  Nucleotide* p_seek=p_head_nucleotide;
  Nucleotide* p_before_deletion;
  Nucleotide* p_after_deletion;
  Nucleotide* head = nullptr; //defines a pointer that holds the first nucleotide in the inputed sequence
  Nucleotide* tail = nullptr; //defines a pointer that holds the last nucleotide int he inputted sequence. At first, since there is only one nucleotide in the inputted sequence, it will be equal to the first nucleotide

  cout << "Enter a nucleotide sequence:" << endl;
  cout << ">";
  cin >> tempstring;
  cout << "Enter a base pair position:" << endl;
  cout << ">";
  cin >> base_position;
  cout << endl << "Enter a base pair length to delete:" << endl;
  cout << ">";
  cin >> base_length;

  for (int i=1; i<base_position;i++){
    p_seek=p_seek->get_next_nucleotide();
  }
  p_before_deletion=p_seek;
  for (int i=0; i<base_length; i++){
    p_seek=p_seek->get_next_nucleotide();
  }
  p_after_deletion=p_seek->get_next_nucleotide();
  for (int i=0; i<tempstring.length(); i++){
    Nucleotide* new_nuc = new Nucleotide(tempstring[i]);   //loads contents of string into array
    if (head == nullptr){
      head=new_nuc;
      tail=head;
    }
    else{
      tail->set_next_nucleotide(new_nuc); //adds next inputted nucleotide to the end of the linked list
      new_nuc->set_prev_nucleotide(tail); //sets the previous nucleotide of the new tail to the previous tail
      tail = new_nuc; //sets tail pointer to the new tail
    }
  }
  p_before_deletion->set_next_nucleotide(head);
  head->set_prev_nucleotide(p_before_deletion);
  p_after_deletion->set_prev_nucleotide(tail);
  tail->set_next_nucleotide(p_after_deletion);

  for (Nucleotide* p_seek=p_head_nucleotide; p_seek!=nullptr ; p_seek=p_seek->get_next_nucleotide()){
    cout << p_seek->get_nucleotide();
  }
}
// void Replace_DNA_sequence_by_file();
// void Save_edited_DNA_sequence();
ostream& operator <<(ostream& os, const DNAsequence& DNAseq){
    Nucleotide* p_seek;
    for (p_seek=DNAseq.p_head_nucleotide; p_seek!=nullptr ; p_seek=p_seek->get_next_nucleotide()){
    os << p_seek->get_nucleotide();
    }
    return os;
}


//DATABASE FUNCTIONS
DNADatabase::DNADatabase(){
  p_head_DNAsequence=nullptr;
}
void DNADatabase::addfile(string filename_in){
  DNAsequence* p_temp=p_head_DNAsequence;

  if (p_head_DNAsequence==nullptr){
    p_head_DNAsequence= new DNAsequence(filename_in);
    return;
  }
  while(p_temp->get_next_DNAsequence()!=nullptr){
    p_temp=p_temp->get_next_DNAsequence();
  }
  DNAsequence* new_DNAsequence= new DNAsequence(filename_in);
  p_temp->set_Next_DNAsequence(new_DNAsequence);
  new_DNAsequence->set_prev_DNAsequence(p_temp);
  cout << "filename being added:  " << filename_in << endl;
}
// void DNADatabase::printnames(){
//   vector<>
//   while(p_head_DNAsequence!=nullptr){
//
//     cout << "hello" << endl;
//   }
// }
string DNADatabase::deque_DNAsequence(){
  DNAsequence* p_seek;
  DNAsequence* p_temp;
  string removed_name;
  for (p_seek=p_head_DNAsequence; p_seek != nullptr; p_seek=p_seek->get_next_DNAsequence()){
    if ((p_seek==p_head_DNAsequence)&&(p_seek->get_next_DNAsequence()==nullptr)){
      removed_name=p_seek->getfilename();
      delete p_seek;
      p_head_DNAsequence=nullptr;
    }
    else if (p_seek->get_next_DNAsequence()->get_next_DNAsequence()==nullptr){
      removed_name=p_seek->get_next_DNAsequence()->getfilename();
      delete p_seek->get_next_DNAsequence();
      p_seek->set_Next_DNAsequence(nullptr);
    }
  }
  cout << removed_name;
  return removed_name;
}
void DNADatabase::Analyse_the_DNA_database(){
  string file_in;
  cout << "Enter a file with a .fna extension" << endl << ">";
  cin >> file_in;

}
string DNADatabase::choosefile(int choice2){
  DNAsequence* p_seek=p_head_DNAsequence;
  for (int counter=1; counter<choice2 ; counter++){
  p_seek=p_seek->get_next_DNAsequence();
  }
  return p_seek->getfilename();
}
DNAsequence* DNADatabase::get_p_head_DNAsequence(){
  return p_head_DNAsequence;
}
DNAsequence* DNADatabase::getfilepointer(int choice2){
  DNAsequence* p_seek=p_head_DNAsequence;
  for (int counter=1; counter<choice2 ; counter++){
    p_seek=p_seek->get_next_DNAsequence();
  }
  return p_seek;
}
int DNADatabase::size_of_database(){
  int counter=0;
  DNAsequence* p_temp=p_head_DNAsequence;
  while(p_temp!=nullptr){
    p_temp=p_temp->get_next_DNAsequence();
    counter++;
  }
  return counter;
}
ostream& operator <<(ostream& os, const DNADatabase& DNAdtb){
    DNAsequence* p_seek;
    int counter=1;
    for (p_seek=DNAdtb.p_head_DNAsequence; p_seek!=nullptr ; p_seek=p_seek->get_next_DNAsequence()){
    os << "(" << counter << ")" << p_seek->getfilename() << endl;
    counter ++;
    }
    return os;
}
// string DNADatabase::pop_DNAsequence(){
//     DNAsequence* p_seek;
//     string removed_name;
//     removed_name=p_seek->getfilename();
//     p_seek=p_head_DNAsequence->get_next_DNAsequence();
//     delete p_head_DNAsequence;
//     p_head_DNAsequence=p_seek;
//     return removed_name;
// }
