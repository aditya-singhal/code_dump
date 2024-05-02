#include "file_system.h"

/**************************************************
Function name: File()
Description: Constructor
Parameters: None
Return type: None
**************************************************/
File::File(){
	//std::cout << "File constructor called\t" << this << "\n";
}

/**************************************************
Function name: File()
Description: Constructor
Parameters: None
Return type: None
**************************************************/
//Pass these values from derived constructor
File::File(std::string name, Folder *parent) {
	this->filename = name;
	this->parent = parent;

	//std::cout << "File constructor called\t" << this << "\n";
}

/**************************************************
Function name: ~File()
Description: Destructor
Parameters: None
Return type: None
**************************************************/
File::~File(){
	//std::cout << "File destructor called\t" << this << "\n";
	//this->parent->file_contents.erase(this);
}

/**************************************************
Function name: move()
Description: Move a file
Parameters: None
Return type: None
**************************************************/
void File::move(std::string new_name, Folder *new_parent ) {
	this->filename = new_name;
	this->parent = new_parent;
}

/**************************************************
Function name: name()
Description: Returns the name of the file
Parameters: None
Return type: 
**************************************************/
std::string File::name(){
	return this->filename;
}

/**************************************************
Function name: set_filename()
Description: set filename
Parameters: filename
Return type: None
**************************************************/
void File::set_filename(std::string filename){
	this->filename = filename;
}

/**************************************************
Function name: set_parent()
Description: set parent of the file
Parameters: parent pointer
Return type: None
**************************************************/
void File::set_parent(Folder *parent){
	this->parent = parent;
}

/**************************************************
Function name: get_parent()
Description: get parent of the file
Parameters: void
Return type: parent pointer
**************************************************/
Folder* File::get_parent(){
	return this->parent;
}

/**************************************************
Function name: Folder()
Description: Constructor
Parameters: namem, path
Return type: None
**************************************************/
Folder::Folder(std::string name, Folder *path) : File(name, path) {
	path->file_contents.push_back(this);
	//std::cout << "Folder constructor called\t" << this << "\n";
}

/**************************************************
Function name: ~Folder
Description: Destructor, Delete the folder and all its contents
Parameters: None
Return type: None
**************************************************/
Folder::~Folder() {
	//std::cout << "Folder destructor called\t" << this << "\n";
	std::list<File*> :: iterator list_itr;
	list_itr = this->file_contents.begin();

	//Delete contents of the folder
	for(; list_itr != this->file_contents.end(); ++list_itr) {
		delete(*list_itr);
	}
	this->file_contents.clear();

	list_itr = this->parent->file_contents.begin();
	for(; list_itr != this->parent->file_contents.end(); ++list_itr) {
		if( this->name() == (*list_itr)->name()){
			this->parent->file_contents.erase(list_itr);
			break;
		}
	}
}

/**************************************************
Function name: list()
Description: Print file name, path and folder contents (file names) to std::cout
Parameters: None
Return type: None
**************************************************/
void Folder::list() {
	std::list<File*> :: iterator list_itr;
	File *file_ptr = NULL;

    for(list_itr = this->file_contents.begin(); list_itr != this->file_contents.end(); ++list_itr) {
        file_ptr = *list_itr;
        std::cout << file_ptr->name() << "\t";
    }
    std::cout << "\n";
}

/**************************************************
Function name: name()
Description: Folder names have a "/" suffix
Parameters: None
Return type: name
**************************************************/
std::string Folder::name() {
	return (File::name() + "/");
}

/**************************************************
Function name: insert()
Description: insert a file, Add an element to file_contents list
Parameters: new file
Return type: None
**************************************************/
void Folder::insert(File *new_child) {
	//check if parent is need to change or not
	this->file_contents.push_back(new_child);
}

/**************************************************
Function name: erase()
Description: Erase a file, Remove an existing element from file_contents
Parameters: pointer to file
Return type: None
**************************************************/
void Folder::erase(File *new_child){
	std::list<File*> :: iterator list_itr;
	File *file_ptr = NULL;

	list_itr = this->file_contents.begin();
	file_ptr = *list_itr;
	while ( list_itr != file_contents.end() ){
		file_ptr = *list_itr;

		if (file_ptr->name() == new_child->name()) {
			this->file_contents.erase(list_itr);
			//delete(file_ptr);
			break;
		}
		list_itr++;
	}
}

/**************************************************
Function name: move()
Description: Move folder to a diffent name and/or path
Parameters: new name, new path
Return type: None
**************************************************/
void Folder::move(std::string new_name, Folder *new_path) {
	bool is_file_present = false;
	File* file_ptr = NULL;
	std::list<File*> :: iterator list_itr;

	//Renaming a folder
	if (this->parent == new_path) {
		this->set_filename(new_name);
	} else {
		is_file_present = new_path->is_file_present(new_name);
		if (is_file_present == false){
			std::cout << "Moving folder...\n";
			
			list_itr = this->parent->file_contents.begin();
			while ( list_itr != file_contents.end() ){
				file_ptr = *list_itr;
				if (file_ptr->name() == this->name()) {
					this->file_contents.erase(list_itr);
					new_path->file_contents.push_back(file_ptr);
					file_ptr->set_filename(new_name);
					file_ptr->set_parent(new_path);
					break;
				}
				list_itr++;
			}
		} else {
			std::cout << "File already present\n";
		}
	}
}

/**************************************************
Function name: is_file_present()
Description: To check if a file is present in a folder or not
Parameters: pointer to file
Return type: true if file is present, else return false
**************************************************/
bool Folder::is_file_present(std::string filename){
	std::list<File*> :: iterator list_itr;
	File *current_file = NULL;
	bool is_file_found = false;

	list_itr = this->file_contents.begin();
	while ( list_itr != this->file_contents.end() ){
		current_file = *list_itr;

		if (current_file->name() == filename ){
			is_file_found = true;
			break;
		}
		list_itr++;
	}
	return is_file_found;
}

Root* Root::theInstance;

/**************************************************
Function name: move()
Description: move folder
Parameters: None
Return type: None
**************************************************/
void Root::move(std::string new_name, Folder *new_path){

}

/**************************************************
Function name: Document()
Description: Constructor
Parameters: name, path
Return type: None
**************************************************/
Document::Document(std::string name, Folder *path) : File(name, path)  {
	//std::cout << "Document constructor called\t" << this << "\n";
	path->insert(this);
}

/**************************************************
Function name: Document()
Description: Destructor, Delete the file
Parameters: None
Return type: None
**************************************************/
Document::~Document(){

}

/**************************************************
Function name: list()
Description: Print file name and path to std::cout
Parameters: None
Return type: None
**************************************************/
void Document::list(){
	std::cout << this->filename;
}

/**************************************************
Function name: move()
Description: Move file to a diffent name and/or path
Parameters: new name, new path
Return type: None
**************************************************/
void Document::move(std::string new_name, Folder *new_path) {
	bool is_file_present = false;
	
	//Renaming a file
	if (this->parent == new_path) {
		this->set_filename(new_name);
	} else {
		is_file_present = new_path->is_file_present(new_name);
		if (is_file_present == false){
			std::cout << "Moving file...\n";
			this->parent->erase(this);
			new_path->insert(this);
			this->set_filename(new_name);
			this->set_parent(new_path);
		} else {
			std::cout << "File already present\n";
		}
	}
}

/**************************************************
Function name: Softlink()
Description: Constructor
Parameters: name, file, path 
Return type: None
**************************************************/
Softlink::Softlink(std::string name, File *link_target, Folder *path) : File(name, path){
	//std::cout << "Softlink constructor called\t" << this << "\n";
	path->insert(this);
	this->link = link_target;
}

/**************************************************
Function name: list()
Description: Print file name and path to std::cout
Parameters: None
Return type: None
**************************************************/
void Softlink::list(){
	this->link->list();
}

/**************************************************
Function name: name()
Description: Softlink names have a "@" suffix
Parameters: None
Return type: @name
**************************************************/
std::string Softlink::name() { 
	return (File::name() + "@");
}

/**************************************************
Function name: move()
Description: Move file to a different name and/or path
Parameters: new name, new path
Return type: None
**************************************************/
void Softlink::move(std::string new_name, Folder *new_path){
	bool is_file_present = false;

	//Renaming a softlink
	if (this->parent == new_path) {
		this->set_filename(new_name);
	} else {
		is_file_present = new_path->is_file_present(new_name);
		if (is_file_present == false){
			std::cout << "Moving softlink...\n";
			this->parent->erase(this);
			new_path->insert(this);
			this->set_filename(new_name);
			this->set_parent(new_path);
		} else {
			std::cout << "Softlink already present\n";
		}
	}
}

/**************************************************
Function name: ~Softlink()
Description: Destructor, Delete the link
Parameters: None
Return type: None
**************************************************/
Softlink::~Softlink(){

}
