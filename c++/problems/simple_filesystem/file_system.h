#ifndef __FILE_SYSTEM_H__
#define __FILE_SYSTEM_H__

#include <iostream>
#include <list>
#include <iterator>
#include <string>

class Folder;

class File {
public:
    File(std::string name, Folder *parent);
    File();
    virtual ~File();
    // ls command
    virtual void list() = 0;

    // new_name could be identical to current name
    // new_parent could be identical to current parent
    // Must erase self from current parent and insert self to new parent
    virtual void move(std::string new_name, Folder *new_parent);
    virtual std::string name();
    void set_filename(std::string filename);
    void set_parent(Folder *parent);
    Folder* get_parent();

protected:
    std::string filename;
    Folder *parent;
};

class Folder : public File {
public:

    Folder(std::string name, Folder *path);
    void list();
    void move(std::string new_name, Folder *new_path);
    std::string name();
    ~Folder();
    void insert(File *new_child);
    void erase(File *new_child);
    bool is_file_present(std::string filename);
private:
    //Folder contents
    std::list<File *> file_contents;
};

// Class "Root" represents the "/" root folder.
// There can be only one instance of root folder
class Root: public Folder {
public:
    static Root* GetInstance() {
        if (theInstance == NULL) {
            theInstance = new Root();
        }
        return theInstance;
    }
 
private:
    // Root is its own parent
    Root() : Folder("/", this) { }
 
    // Can't move root
    void move(std::string new_name, Folder *new_path);
    static Root* theInstance;
};


class Document: public File {
public:
    Document(std::string name, Folder *path);
    void list();
    void move(std::string new_name, Folder *new_path);
    ~Document();
};

class Softlink: public File {
public:
    Softlink(std::string name, File *link_target, Folder *path); 
    void list();
    std::string name();
    void move(std::string new_name, Folder *new_path);
    ~Softlink();

private:
    File* link;
};

#endif