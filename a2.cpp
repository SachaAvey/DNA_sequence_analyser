#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include "tictoc.h"
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
      int length;
      string filename;
      Nucleotide* p_head_nucleotide;
      DNAsequence* p_next_DNAsequence;
      DNAsequence* p_prev_DNAsequence;
      Nucleotide* p_tail_nucleotide;
  public:
    DNAsequence();
    DNAsequence(string);
    int getLength();
    void copylist(DNAsequence*);
    string getfilename();
    void set_filename(string);
    void set_p_head_nucleotide(Nucleotide*);
    void set_p_tail_nucleotide(Nucleotide*);
    Nucleotide* get_Nucleotide_head();
    void set_Next_DNAsequence(DNAsequence*);
    void set_prev_DNAsequence(DNAsequence*);
    DNAsequence* get_next_DNAsequence();
    void add_nucleotide(char);
    void add_nucleotide_front(char);
    void Find_DNA_sequence_by_input(TicToc);
    void Find_DNA_sequence_by_file(TicToc, string);
    void Add_DNA_sequence_by_input(TicToc);
    void Add_DNA_sequence_by_file(TicToc);
    void Delete_DNA_sequence_by_input(TicToc);
    void Replace_DNA_sequence_by_input(TicToc);
    void Replace_DNA_sequence_by_file(TicToc);
    //void Save_edited_DNA_sequence(DNAsequence , TicToc);
    void add_DNA_sequence(int,Nucleotide*, Nucleotide*, Nucleotide*);
    void find_sequence(Nucleotide*, int ,DNAsequence);
    void replace_DNA_sequence(int, int, int ,Nucleotide*,Nucleotide*, Nucleotide*);
    friend ostream& operator <<(ostream& os, const DNAsequence& DNAseq);
    // ~DNAsequence();
};
class DNADatabase: public DNAsequence{
  private:
    DNAsequence* p_head_DNAsequence;
    DNAsequence* p_tail_DNAsequence;
  public:
    DNADatabase();
    void addfile(string);
    void addfile(string, DNAsequence*);
    DNAsequence* get_p_tail_DNAsequence();
    void printnames();
    void Analyse_the_DNA_database(TicToc time, string tempstring);
    string choosefile(int);
    string deque_DNAsequence();
    int size_of_database();
    DNAsequence* get_p_head_DNAsequence();
    DNAsequence* get_file_pointer(int choice2);
    // void Save_edited_DNA_sequence(DNAsequence, TicToc);
    // ~DNADatabase();
    friend ostream& operator <<(ostream& os, const DNADatabase& DNAdtb);
};
void enter_file_name(DNADatabase*,TicToc);
void Save_edited_DNA_sequence(DNAsequence, TicToc);
bool whole_db=false;

int main(){
  DNADatabase dna_db;
  TicToc time;
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
        cout << "Invalid input" << endl;
        cin.clear();
        cin.ignore(500, '\n');
      }
    }
    if(choice==1){
      cout << "Enter the DNA file names:" << endl;
      cout << "For multiple files, separate them by a comma. Only .fna are recognised" << endl;
      enter_file_name(&dna_db, time);
    }
    else if (choice==2){
      bool repeat=true;
      int choice2;
      int choice3=0;
      string file_choice_2;
      DNAsequence* file_pointer;
      DNAsequence new_file;
      while(choice3!=9){
        while(repeat){
          cout << "Select a DNA to process:" << endl;
          cout << "dna_db:     " << endl;
          cout << dna_db << endl;
          cout << "dna db print names fucntion:  " << endl;
          cout << ">";
          cin >> choice2;
          if (cin.fail())
          {
            cout << "Invalid input" << endl;
            cin.clear();
            cin.ignore(500, '\n');
          }
          if(choice2<=dna_db.size_of_database()){
            file_choice_2=dna_db.choosefile(choice2);
            cout << endl<< "currently processing file:  " << file_choice_2 << endl;
            file_pointer=dna_db.get_file_pointer(choice2); //returns pointer that points to the DNA sequence file we will be analysing
            new_file = *file_pointer;
            repeat=false;
          }
        }
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
        if (cin.fail())
        {
          cout << "Invalid input" << endl;
          cin.clear();
          cin.ignore(500, '\n');
        }
        if (choice3==1){
          new_file.Find_DNA_sequence_by_input(time);
        }
        else if (choice3==2){
          string tempstring;
          cout << "Enter a file that you would like to look for in the specified file:" << endl;
          cout << ">";
          cin >> tempstring;
          new_file.Find_DNA_sequence_by_file(time, tempstring);
        }
        else if (choice3==3){
          new_file.Add_DNA_sequence_by_input(time);
        }
        else if (choice3==4){
          new_file.Add_DNA_sequence_by_file(time);
        }
        else if (choice3==5){
          new_file.Delete_DNA_sequence_by_input(time);
        }
        else if (choice3==6){
          new_file.Replace_DNA_sequence_by_input(time);
        }
        else if (choice3==7){
          new_file.Replace_DNA_sequence_by_file(time);
        }
        if (choice3==8){
          //dna_db.
          Save_edited_DNA_sequence(new_file,time);
        }
      }
    }

    else if (choice==3){
      cout << "Enter a file with a .fna extension that you would like to look for in the database:" << endl;
      cout << ">";
      string tempstring;
      cin >> tempstring;
      dna_db.Analyse_the_DNA_database(time, tempstring);
    }
    else if (choice==4){
      repeat=false;
    }
    choice=0;
  }
  return 0;
}

void enter_file_name(DNADatabase *dna_db, TicToc time){
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
  time.tic();
  for(int i=0; i<v.size(); i++){
    bool valid = true;
    string string_vector=v[i];
    cout << endl << "processing " << string_vector << endl;
    for(int j=0; j<string_vector.size();j++){
      if (string_vector[j]==' '){
        string_vector.erase(string_vector.begin()+j);
        j--;
      }
      else if(string_vector[j]!=' '){
        break;
      }
    }
    for(int k=string_vector.size();k>0;k--){
      if (string_vector[k]==' '){
        string_vector.erase(string_vector.begin()+k);
      }
      else if(string_vector[k]!=' ')
      break;
    }
    v[i]=string_vector;
    if (v[i].size() < 5){
      v.erase(v.begin()+i); //if file entered is less than 5 characters long it will be ignored as it cannot have a .fda at the end of the name
      i--;
      valid=false;
      cout << "Invalid file name.\n";
    } else if (v[i].substr(v[i].size()-4,4)!=".fna"){ //checks if last 4 characters in the entry are .fna
      v.erase(v.begin()+i); //if extension != fna the entry will be ignored
      i--;
      valid=false;
      cout << "Invalid file name.\n";
    }
    if (valid==true){
      string tempstring;
      tempstring=v[i];
      dna_db->addfile(tempstring); //if the name is in the proper .fna format it will be added to the database
      file_pointer=dna_db->get_p_tail_DNAsequence();
      fstream in;             //used to open the file
      in.open(tempstring, fstream::in);   //opens the file that we entered into the program prviously and names the data stream that we will be getting data from "in"
      if (in.fail())          //checks to see if the file has failed to open
      {
        cout << "Input file opening failed.\n";   //if file failed to open the program will output this
      }
      else{
        cout << "give the file a second to load... " << endl;
        if (first){ //if its the first file being opened, the head of the list of files gets set to the first input
          first = false;
        }
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
            // cout << nucleotide;
          }
        }
      }
      in.close();           //closes the input file
    }
  }
  time.toc();
  cout << endl;
  cout << time << endl;
}
void Save_edited_DNA_sequence(DNAsequence DNAsequence_in, TicToc time){
  string filename;
  int counter=0;
  Nucleotide* p_seek=DNAsequence_in.get_Nucleotide_head();
  cout << "enter a filename for the file you want to save: " << endl;
  cout << ">";
  cin.ignore(); //clearing cin
  getline(cin,filename); //getting all inputs from user input, including white space
  time.tic();
  ofstream myfile (filename);
  if (myfile.is_open())
  {
    myfile << ">descriptor line: this file is an edited version of " << DNAsequence_in.getfilename() << endl;
    while(p_seek!=nullptr){
      counter++;
      myfile << p_seek->get_nucleotide();
      p_seek=p_seek->get_next_nucleotide();
      if (counter%70==0){
        myfile << "\n";
      }
    }
    myfile.close();
  }
  else cout << "Unable to open file";
  time.toc();
  cout << endl;
  cout << time << endl;
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
  length = 0;
  filename="filename";
  p_head_nucleotide=nullptr;
  p_next_DNAsequence = nullptr;
  p_tail_nucleotide=nullptr;
}
DNAsequence::DNAsequence(string filename_in){
  length = 0;
  filename=filename_in;
  p_next_DNAsequence = nullptr;
}
void DNAsequence::copylist(DNAsequence* p_list){
  Nucleotide* p_seek=p_list->get_Nucleotide_head();
  while(p_seek!=nullptr){
    add_nucleotide(p_seek->get_nucleotide());
    p_seek=p_seek->get_next_nucleotide();
  }
}
string DNAsequence::getfilename(){
  return filename;
}
int DNAsequence::getLength(){
  return length;
}
void DNAsequence::set_filename(string filename_in){
  filename=filename_in;
}
void DNAsequence::set_p_head_nucleotide(Nucleotide* p_in){
  p_head_nucleotide=p_in;
}
void DNAsequence::set_p_tail_nucleotide(Nucleotide* p_in){
  p_tail_nucleotide=p_in;
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
Nucleotide* DNAsequence::get_Nucleotide_head(){
  return p_head_nucleotide;
}
void DNAsequence::add_nucleotide(char nucleotide_in){
  length++;
  if (p_head_nucleotide==nullptr){
    p_head_nucleotide= new Nucleotide(nucleotide_in);
    p_tail_nucleotide = p_head_nucleotide;
    return;
  }
  Nucleotide* new_nuc= new Nucleotide(nucleotide_in);
  p_tail_nucleotide->set_next_nucleotide(new_nuc);
  new_nuc->set_prev_nucleotide(p_tail_nucleotide);
  p_tail_nucleotide = new_nuc;
}
void DNAsequence::add_nucleotide_front(char nucleotide_in){
  // Nucleotide* p_temp=p_head_nucleotide;
  if(p_head_nucleotide==nullptr){
    p_head_nucleotide= new Nucleotide(nucleotide_in);
    p_tail_nucleotide = p_head_nucleotide;
    return;
  }
  Nucleotide* new_nuc= new Nucleotide(nucleotide_in);
  p_head_nucleotide->set_prev_nucleotide(new_nuc);
  new_nuc->set_next_nucleotide(p_head_nucleotide);
  p_head_nucleotide= new_nuc;
}
void DNAsequence::Find_DNA_sequence_by_input(TicToc time){
  string input;
  Nucleotide* p_seek_file= p_head_nucleotide;
  DNAsequence input_DNAsequence;    //defines new dna sequence linked list to hold inputted sequence
  int start_index=0;    //start and end index keep tract of where the matched sequence lies in the file
  int end_index=0;
  int base_length=0;
  // Nucleotide* p_print_10_temp; //defines new pointer to a nucleotide that we will use to print 10 bases before and after match

  cout << "Enter a nucleotide sequence that you would like to look for in the specified file:" << endl;
  cout << ">";
  cin >> input;
  cout << endl;
  time.tic();
  char DNAsequencearr[input.length()];            //creates an array of the same size as our inout that we will use to load the contents of our input into its own linked list to compare with the file we want
  for (int i=0; i<input.length(); i++){   //loads contents of string into array
    if (input[i]!=' ')
    input_DNAsequence.add_nucleotide(input[i]);    //adds nucleotide to new DNA sequence
    base_length++;
  }
  find_sequence(p_seek_file,base_length,input_DNAsequence);
  time.toc();
  cout << endl;
  cout << time << endl;
}
void DNAsequence::Find_DNA_sequence_by_file(TicToc time, string tempstring){
  Nucleotide* p_seek_file= p_head_nucleotide; //defines pointer that iterates through file we are looking at
  // Nucleotide* p_seek_input; //defines pointer that iterates through the input file
  bool first = true;    //bool vlaue for the first line of the file, which we want to ignore as it only holds descriptors and not nucleotide data
  DNAsequence input_DNAsequence;    //defines new dna sequence linked list to hold inputted file
  int base_length=0;
  int start_index=0;    //start and end index keep tract of where the matched sequence lies in the file
  int end_index=0;
  Nucleotide* p_print_10_temp; //defines new pointer to a nucleotide that we will use to print 10 bases before and after match
  time.tic();

  fstream in;             //used to open the file
  in.open(tempstring, fstream::in);   //opens the file that we entered into the program and names the data stream that we will be getting data from "in"
  if (in.fail())          //checks to see if the file has failed to open
  {
    cout << "Input file opening failed.\n";   //if file failed to open the program will output this
    return;
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
      if (nucleotide!='\n' && !in.eof()){
        input_DNAsequence.add_nucleotide(nucleotide);
        // cout << "nucleotide:  " << nucleotide << endl;
        base_length++;
      }
    }
    in.close();           //closes the input file
  }
  find_sequence(p_seek_file,base_length,input_DNAsequence);
  time.toc();
  cout << endl;
  if (!whole_db){
    cout << time << endl;
  }
}
void DNAsequence::Add_DNA_sequence_by_input(TicToc time){
  string input;
  int start_index;    //start and end index keep tract of where the matched sequence lies in the file
  int end_index;
  int base_length=0;
  Nucleotide* p_seek_file= p_head_nucleotide; //defines pointer that iterates through file we are looking at as the head pointer of
  Nucleotide* p_print_10_temp; //defines new pointer to a nucleotide that we will use to print 10 bases before and after match
  cout << "Enter a nucleotide sequence that you would like to enter to the file: " << endl;
  cout << ">";
  cin >> input;
  Nucleotide* head = new Nucleotide(input[0]); //defines a pointer that holds the first nucleotide in the inputed sequence
  Nucleotide* tail = head; //defines a pointer that holds the last nucleotide in the inputted sequence. At first, since there is only one nucleotide in the inputted sequence, it will be equal to the first nucleotide
  base_length++;
  for (int i=1; i<input.length(); i++){
    Nucleotide* new_nuc = new Nucleotide(input[i]);   //loads contents of string into array
    tail->set_next_nucleotide(new_nuc); //adds next inputted nucleotide to the end of the linked list
    new_nuc->set_prev_nucleotide(tail); //sets the previous nucleotide of the new tail to the previous tail
    tail = new_nuc; //sets tail pointer to the new tail
    base_length++;
  }

  cout << "Enter the base pair you would like to enter your sequence at: " << endl;
  cout << ">";
  cin >> start_index;
  if (start_index<0 || start_index>getLength()){
    cout << "Invalid base pair position" << endl;
    return;
  }
  time.tic();
  for (int i=0; i<start_index; i++){  //finds pointer that points to where we want to insert new sequence
    p_seek_file=p_seek_file->get_next_nucleotide();
  }
  add_DNA_sequence(start_index,p_seek_file,tail,head);

  end_index=start_index+base_length-1;
  DNAsequence ten_bases_before;
  DNAsequence ten_bases_after;
  cout << "First base pair position: " << start_index << endl;
  cout << "Last base pair position: " << end_index << endl;
  cout << "base pair length: " << base_length << endl;
  cout << "10 base pairs preceding the sequence: ";
  //obtaining 10 previous base pairs
  p_print_10_temp=head;//sets print_10 pointer to the last nucleotide of the inputted sequenc
  for (int i=0; i<10; i++ ){
    if(p_print_10_temp->get_prev_nucleotide()!=nullptr){
      p_print_10_temp=p_print_10_temp->get_prev_nucleotide();
      ten_bases_before.add_nucleotide_front(p_print_10_temp->get_nucleotide());
    }
  }
  cout << ten_bases_before << endl;
  cout << "Added sequence:  ";
  for (Nucleotide* print=head; print!=tail->get_next_nucleotide(); print=print->get_next_nucleotide())
    cout << print->get_nucleotide();
  cout << endl;
  cout << "10 base pairs following matched sequence:  ";
  // obtaining 10 following base pairs
  p_print_10_temp=tail; //sets print_10 pointer to the last nucleotide of the inputted sequence
  for (int i=0; i<10; i++ ){
    if(p_print_10_temp->get_next_nucleotide()!=nullptr){
      p_print_10_temp=p_print_10_temp->get_next_nucleotide();
      ten_bases_after.add_nucleotide(p_print_10_temp->get_nucleotide());
    }
  }
  cout << ten_bases_after;
  cout << endl;
  time.toc();
  cout << endl;
  cout << time << endl;
}
void DNAsequence::Add_DNA_sequence_by_file(TicToc time){
  string tempstring;
  int base_length_added=0;
  int start_index;    //start and end index keep tract of where the matched sequence lies in the file
  int end_index;
  Nucleotide* p_seek_file= p_head_nucleotide; //defines pointer that iterates through file we are looking at, starting with the first one
  Nucleotide* head=nullptr; //defines pointer which refers to the first nucleotide in input file
  Nucleotide* tail=nullptr; //defines pointer which refers to the last nucleotide in input file
  Nucleotide* p_print_10_temp; //defines new pointer to a nucleotide that we will use to print 10 bases before and after match

  cout << "Enter a file that you would like to insert into the specified file:" << endl;
  cout << ">";
  cin >> tempstring;

  fstream in;             //used to open the file
  in.open(tempstring, fstream::in);   //opens the file that we entered into the program and names the data stream that we will be getting data from "in"
  if (in.fail())          //checks to see if the file has failed to open
  {
    cout << "Input file opening failed.\n";   //if file failed to open the program will output this
    return;
  }
  else{
    cout << "give the file a second to load... " << endl;
    char nucleotide_in;
    while(!in.eof()){ //the first line of a .fna file is a descriptor line, hence this while loop gets the first line but does not store it anywhere
      nucleotide_in=in.get();
      if (nucleotide_in=='\n')
      break;
    }
    while(!in.eof()){   //gets each nucleotide from the rest of the file and enters it into a new DNAsequence
      nucleotide_in=in.get();
      Nucleotide* new_nuc = new Nucleotide(nucleotide_in);
      if (nucleotide_in!='\n' && !in.eof()){
        if(head==nullptr){
          head=new_nuc;
          tail=head;
          base_length_added++;
        }
        else {
          tail->set_next_nucleotide(new_nuc);
          new_nuc->set_prev_nucleotide(tail);
          tail=new_nuc;
          base_length_added++;
        }
      }
    }
  }

  cout << "Enter the base pair you would like to enter your sequence at: " << endl;
  cout << ">";
  cin >> start_index;
  if (start_index<0 || start_index>getLength()){
    cout << "Invalid base pair position" << endl;
    return;
  }
  time.tic();
  for (int i=0; i<start_index; i++){  //finds pointer that points to where we want to insert new sequence
    p_seek_file=p_seek_file->get_next_nucleotide();
  }
  add_DNA_sequence(start_index,p_seek_file,tail,head);
  start_index=start_index;
  end_index=start_index+base_length_added-1;
  DNAsequence ten_bases_before;
  DNAsequence ten_bases_after;
  cout << "First base pair position: " << start_index << endl;
  cout << "Last base pair position: " << end_index << endl;
  cout << "base pair length: " << base_length_added << endl;
  cout << "10 base pairs preceding the sequence: ";
  //obtaining 10 previous base pairs
  p_print_10_temp=head;//sets print_10 pointer to the last nucleotide of the inputted sequenc
  for (int i=0; i<10; i++ ){
    if(p_print_10_temp->get_prev_nucleotide()!=nullptr){
      p_print_10_temp=p_print_10_temp->get_prev_nucleotide();
      ten_bases_before.add_nucleotide_front(p_print_10_temp->get_nucleotide());
    }
  }
  cout << ten_bases_before << endl;
  cout << "Added sequence:  ";
  for (Nucleotide* print=head; print!=tail->get_next_nucleotide(); print=print->get_next_nucleotide())
    cout << print->get_nucleotide();
  cout << endl;
  cout << "10 base pairs following matched sequence:  ";
  // obtaining 10 following base pairs
  p_print_10_temp=tail; //sets print_10 pointer to the last nucleotide of the inputted sequence
  for (int i=0; i<10; i++ ){
    if(p_print_10_temp->get_next_nucleotide()!=nullptr){
      p_print_10_temp=p_print_10_temp->get_next_nucleotide();
      ten_bases_after.add_nucleotide(p_print_10_temp->get_nucleotide());
    }
  }
  cout << ten_bases_after; //prints the
  cout << endl;
  time.toc();
  cout << endl;
  cout << time << endl;
}
void DNAsequence::Delete_DNA_sequence_by_input(TicToc time){
  int base_length_deleted;
  int start_index;    //start and end index keep tract of where the matched sequence lies in the file
  int end_index;
  Nucleotide* p_seek=p_head_nucleotide;
  Nucleotide* p_before_deletion;
  Nucleotide* p_after_deletion;
  Nucleotide* p_print_10_temp; //defines new pointer to a nucleotide that we will use to print 10 bases before and after match
  DNAsequence deleted_sequence;
  cout << "Enter a base pair position:" << endl;
  cout << ">";
  cin >> start_index;
  if (start_index<0 || start_index>getLength()){
    cout << "Invalid base pair position" << endl;
    return;
  }
  cout << endl << "Enter a base pair length to delete:" << endl;
  cout << ">";
  cin >> base_length_deleted;
  time.tic();
  if (start_index==0){
    p_before_deletion=nullptr;
  }
  else{
    for (int i=1; i<start_index;i++){
      p_seek=p_seek->get_next_nucleotide();
    }
    p_before_deletion=p_seek;
  }
  for (int i=0; i<base_length_deleted; i++){
    if (p_seek->get_next_nucleotide()!=nullptr){
      if(start_index==0){
        deleted_sequence.add_nucleotide(p_seek->get_nucleotide());
        p_seek=p_seek->get_next_nucleotide();
      }
      else{
        p_seek=p_seek->get_next_nucleotide();
        deleted_sequence.add_nucleotide(p_seek->get_nucleotide());

      }
    }
  }
  if (p_before_deletion!=nullptr){
    p_after_deletion=p_seek->get_next_nucleotide();
  } else {
    p_after_deletion=p_seek;
  }
  if (p_before_deletion!=nullptr){
    p_before_deletion->set_next_nucleotide(p_after_deletion);
  } else {
    p_head_nucleotide = p_after_deletion;
  }
    p_after_deletion->set_prev_nucleotide(p_before_deletion);

  start_index=start_index;
  end_index=start_index+base_length_deleted-1;
  DNAsequence ten_bases_before;
  DNAsequence ten_bases_after;
  cout << "10 base pairs preceding the sequence: ";
  //obtaining 10 previous base pairs
  p_print_10_temp=p_after_deletion;//sets print_10 pointer to the nucleotide after deleted sequence
  for (int i=0; i<10; i++ ){
    if(p_print_10_temp!=nullptr){
      if(p_print_10_temp->get_prev_nucleotide()!=nullptr){
        p_print_10_temp=p_print_10_temp->get_prev_nucleotide();
        ten_bases_before.add_nucleotide_front(p_print_10_temp->get_nucleotide());
      }
    }
  }
  cout << ten_bases_before << endl;
  cout << "Deleted sequence:  " << deleted_sequence << endl;

  cout << "10 base pairs following deleted sequence:  ";
  // obtaining 10 following base pairs
  p_print_10_temp=p_after_deletion; //sets print_10 pointer to the nucleotide before deleted sequence
  for (int i=0; i<10; i++ ){
    if(p_print_10_temp->get_next_nucleotide()!=nullptr && p_print_10_temp!=nullptr){
      ten_bases_after.add_nucleotide(p_print_10_temp->get_nucleotide());
      p_print_10_temp=p_print_10_temp->get_next_nucleotide();
    }
  }
  cout << ten_bases_after << endl;
  cout << "Sequence has been deleted!" << endl;
  cout << "10 base pairs preceding the sequence: " << ten_bases_before << endl;
  cout << "10 base pairs following matched sequence:  " << ten_bases_after << endl;
  time.toc();
  cout << endl;
  cout << time << endl;
}
void DNAsequence::Replace_DNA_sequence_by_input(TicToc time){
  string input;
  int base_length_deleted;
  int start_index;    //start and end index keep tract of where the matched sequence lies in the file

  int base_length_added=0;
  Nucleotide* p_seek=p_head_nucleotide;
  Nucleotide* head = nullptr; //defines a pointer that holds the first nucleotide in the inputed sequence
  Nucleotide* tail = nullptr; //defines a pointer that holds the last nucleotide int he inputted sequence. At first, since there is only one nucleotide in the inputted sequence, it will be equal to the first nucleotide
  cout << "Enter a nucleotide sequence:" << endl;
  cout << ">";
  cin >> input;
  cout << "Enter a base pair position:" << endl;
  cout << ">";
  cin >> start_index;
  if (start_index<0 || start_index>getLength()){
    cout << "Invalid base pair position" << endl;
    return;
  }
  cout << "Enter a base pair length to delete:" << endl;
  cout << ">";
  cin >> base_length_deleted;
  time.tic();
  cout << endl;

  for (int i=0; i<input.length(); i++){
    Nucleotide* new_nuc = new Nucleotide(input[i]);   //loads contents of string into list
    if (head == nullptr){
      head=new_nuc;
      tail=head;
      base_length_added++;
    }
    else{
      tail->set_next_nucleotide(new_nuc); //adds next inputted nucleotide to the end of the linked list
      new_nuc->set_prev_nucleotide(tail); //sets the previous nucleotide of the new tail to the previous tail
      tail = new_nuc; //sets tail pointer to the new tail
      base_length_added++;
    }
  }
  replace_DNA_sequence(start_index,base_length_deleted,base_length_added,p_seek,head,tail);
  time.toc();
  cout << endl;
  cout << time << endl;
}
void DNAsequence::Replace_DNA_sequence_by_file(TicToc time){
  string tempstring;
  int base_length_added=0;
  int base_length_deleted;
  int start_index;    //start and end index keep tract of where the matched sequence lies in the file
  Nucleotide* p_seek=p_head_nucleotide;
  Nucleotide* head = nullptr; //defines a pointer that holds the first nucleotide in the inputed sequence
  Nucleotide* tail = nullptr; //defines a pointer that holds the last nucleotide int he inputted sequence. At first, since there is only one nucleotide in the inputted sequence, it will be equal to the first nucleotide

  cout << "Enter a filename with a .fna extensio to insert into the file:" << endl;
  cout << ">";
  cin >> tempstring;
  cout << "Enter a base pair position:" << endl;
  cout << ">";
  cin >> start_index;
  if (start_index<0 || start_index>getLength()){
    cout << "Invalid base pair position" << endl;
    return;
  }
  cout << "Enter a base pair length to delete:" << endl;
  cout << ">";
  cin >> base_length_deleted;
  time.tic();
  cout << endl;

  fstream in;             //used to open the file
  in.open(tempstring, fstream::in);   //opens the file that we entered into the program and names the data stream that we will be getting data from "in"
  if (in.fail())          //checks to see if the file has failed to open
  {
    cout << "Input file opening failed.\n";   //if file failed to open the program will output this
    return;
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
      if (nucleotide!='\n' && !in.eof()){
        if(head==nullptr){
          head=new_nuc;
          tail=head;
          base_length_added++;
        }
        else {
          tail->set_next_nucleotide(new_nuc);
          new_nuc->set_prev_nucleotide(tail);
          tail=new_nuc;
          base_length_added++;
        }
      }
    }
  }
  replace_DNA_sequence(start_index,base_length_deleted,base_length_added,p_seek,head,tail);
  time.toc();
  cout << endl;
  cout << time << endl;
}
// void DNAsequence::
void DNAsequence::find_sequence(Nucleotide* p_seek_file, int base_length,DNAsequence input_DNAsequence){
  int start_index=-1;
  Nucleotide* p_print_10_temp; //defines new pointer to a nucleotide that we will use to print 10 bases before and after match
  Nucleotide* p_seek_input= input_DNAsequence.get_Nucleotide_head();
  Nucleotide* p_return_to_place;
  bool match=false; //lets user know if a match has been found
  int counter;
  while(p_seek_file!=nullptr){
    start_index++;
    p_seek_input=input_DNAsequence.get_Nucleotide_head();
    p_return_to_place=p_seek_file;
    if (p_seek_file->get_nucleotide()==p_seek_input->get_nucleotide()){
      p_print_10_temp=p_seek_file; //sets print_10 pointer to the first nucleotide in the matched sequence
      for(counter=1; counter<base_length; counter++){
        p_seek_file=p_seek_file->get_next_nucleotide();
        if (p_seek_file==nullptr){
          break;
        }
        p_seek_input=p_seek_input->get_next_nucleotide();
        if(p_seek_file->get_nucleotide()!=p_seek_input->get_nucleotide()){
          break;
        }
      }
      if (counter==base_length){
        cout << endl << "you found a match!" << endl;
        if (whole_db){
          cout << "Filename: " << filename << endl;
        }
        match=true;
        //start_index--;
        int end_index=start_index+base_length-1;
        DNAsequence ten_bases_before;
        DNAsequence ten_bases_after;
        cout << "First base pair position: " << start_index << endl;
        cout << "Last base pair position: " << end_index << endl;
        cout << "base pair length: " << base_length << endl;
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
          if (p_print_10_temp!=nullptr){
            if(p_print_10_temp->get_next_nucleotide()!=nullptr){
              p_print_10_temp=p_print_10_temp->get_next_nucleotide();
              ten_bases_after.add_nucleotide(p_print_10_temp->get_nucleotide());
            } else {break;}
          } else {
            break;
          }
        }
        if (ten_bases_after.get_Nucleotide_head()!=nullptr){
          cout << ten_bases_after << endl;
          //start_index=end_index;
        } else {
          cout << endl;
          break;
        }
      }
    }
    if (p_return_to_place != nullptr){
      p_seek_file=p_return_to_place->get_next_nucleotide();
    } else {
      p_seek_file = nullptr;
    }
  }
  if (match==false)
  cout << "no match was found" << endl;
}
void DNAsequence::add_DNA_sequence(int start_index,Nucleotide* p_seek_file, Nucleotide* tail, Nucleotide* head){
  if(start_index!=0){
    if (p_seek_file != nullptr){  //if sequence is not being added to the end of the original file
      Nucleotide* start = p_seek_file->get_prev_nucleotide(); //start is the nucleotide before the position where we want to insert
      head->set_prev_nucleotide(start); //sets previous node of inserted sequence to where it is being inserted
      start->set_next_nucleotide(head);
      p_seek_file->set_prev_nucleotide(tail); //sets the prev nucleotide of the part of the original sequence after the addition to the end of the addition
      tail->set_next_nucleotide(p_seek_file);//sets the next nucleotide of the added sequence to part of the sequence after insertion
      set_p_tail_nucleotide(tail); //sets the end nucleotide of the file to be the end of the inputted sequence
    }else { //if the sequence is being added to the end of the file
      p_tail_nucleotide->set_next_nucleotide(head); //sets the next node end of the file to the start of the inputted sequence
      head->set_prev_nucleotide(p_tail_nucleotide); //sets the previous node of the inputted sequence to be the end of the file
      set_p_tail_nucleotide(tail); //sets the end nucleotide of the file to be the end of the inputted sequence
    }
  }
  else{
    tail->set_next_nucleotide(p_head_nucleotide);
    p_head_nucleotide->set_prev_nucleotide(tail);
    set_p_head_nucleotide(head);
  }
}
void DNAsequence::replace_DNA_sequence(int start_index, int base_length_deleted, int base_length_added,Nucleotide*p_seek,Nucleotide* head, Nucleotide* tail){
  Nucleotide* p_print_10_temp; //defines new pointer to a nucleotide that we will use to print 10 bases before and after match
  Nucleotide* p_before_deletion;
  Nucleotide* p_after_deletion;
  if (start_index==0){
    p_before_deletion=nullptr;
  }
  else{
    for (int i=1; i<start_index;i++){
      p_seek=p_seek->get_next_nucleotide();
    }
    p_before_deletion=p_seek;
  }
  for (int i=0; i<base_length_deleted; i++){
    if (p_seek->get_next_nucleotide()!=nullptr){
      if(start_index==0){
        p_seek=p_seek->get_next_nucleotide();
      }
      else{
        p_seek=p_seek->get_next_nucleotide();
      }
    }
  }
  if (p_before_deletion!=nullptr){
    p_after_deletion=p_seek->get_next_nucleotide();
  } else {
    p_after_deletion=p_seek;
  }
  if (p_before_deletion!=nullptr){
    p_before_deletion->set_next_nucleotide(head);
    head->set_prev_nucleotide(p_before_deletion);
  }
  else{
    p_head_nucleotide = head;
  }
  p_after_deletion->set_prev_nucleotide(tail);
  tail->set_next_nucleotide(p_after_deletion);

  // start_index=start_index;
  int end_index=start_index+base_length_added-1;
  DNAsequence ten_bases_before;
  DNAsequence ten_bases_after;
  cout << "First base pair position: " << start_index << endl;
  cout << "Last base pair position: " << end_index << endl;
  cout << "base pair length: " << base_length_added << endl;
  cout << "10 base pairs preceding the sequence: ";
  //obtaining 10 previous base pairs
  p_print_10_temp=head;//sets print_10 pointer to the first nucleotide in inserted sequence
  for (int i=0; i<10; i++ ){
    if(p_print_10_temp->get_prev_nucleotide()!=nullptr){
      p_print_10_temp=p_print_10_temp->get_prev_nucleotide();
      ten_bases_before.add_nucleotide_front(p_print_10_temp->get_nucleotide());
    }
  }
  cout << ten_bases_before << endl;
  cout << "Added sequence:  ";
  for (Nucleotide* print=head; print!=tail->get_next_nucleotide(); print=print->get_next_nucleotide())
    cout << print->get_nucleotide();
  cout << endl;
  cout << "10 base pairs following matched sequence:  ";
  // obtaining 10 following base pairs
  p_print_10_temp=tail; //sets print_10 pointer to the last nucleotide in inserted sequence
  for (int i=0; i<10; i++ ){
    if(p_print_10_temp->get_next_nucleotide()!=nullptr){
      p_print_10_temp=p_print_10_temp->get_next_nucleotide();
      ten_bases_after.add_nucleotide(p_print_10_temp->get_nucleotide());
    }
  }
  cout << ten_bases_after;
}
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
  p_tail_DNAsequence=nullptr;
}
void DNADatabase::addfile(string filename_in){

  if (p_head_DNAsequence==nullptr){
    p_head_DNAsequence= new DNAsequence(filename_in);
    p_tail_DNAsequence=p_head_DNAsequence;
    return;
  }
  DNAsequence* p_new_DNAsequence= new DNAsequence(filename_in);
  p_tail_DNAsequence->set_Next_DNAsequence(p_new_DNAsequence);
  p_new_DNAsequence->set_prev_DNAsequence(p_tail_DNAsequence);
  p_tail_DNAsequence=p_new_DNAsequence;

}
void DNADatabase::addfile(string filename, DNAsequence* p_DNAsequence_in){
  if (p_head_DNAsequence==nullptr){
    p_head_DNAsequence= p_DNAsequence_in;
    p_tail_DNAsequence=p_head_DNAsequence;
    return;
  }
  p_DNAsequence_in->set_filename(filename);
  p_DNAsequence_in->set_prev_DNAsequence(p_tail_DNAsequence);
  p_tail_DNAsequence->set_Next_DNAsequence(p_DNAsequence_in);
  p_tail_DNAsequence=p_DNAsequence_in;
}
DNAsequence* DNADatabase::get_p_tail_DNAsequence(){
  return p_tail_DNAsequence;
}
void DNADatabase::Analyse_the_DNA_database(TicToc time, string tempstring){
  time.tic();
  DNAsequence* p_seek=p_head_DNAsequence;
  whole_db = true;
  while(p_seek!=nullptr){
    p_seek->Find_DNA_sequence_by_file(time, tempstring);
    p_seek=p_seek->get_next_DNAsequence();
  }
  whole_db = false;
  time.toc();
  cout << endl;
  cout << time << endl;
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
DNAsequence* DNADatabase::get_file_pointer(int choice2){
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
