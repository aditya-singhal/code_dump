#include "file_system.h"

int main(){

	Folder *root = Root::GetInstance();

	Folder *f_etc = new Folder("etc", root);
	Folder *f_bin = new Folder("bin", root);
	Folder *f_usr = new Folder("usr", root);
	
	std::cout << "Root folder contents:  ";
	root->list();

	Document *f_etc_foo = new Document("foo", f_etc);
	Document *f_etc_bar = new Document("bar", f_etc);
	Folder *f_etc_init = new Folder("init", f_etc);
	Document *f_etc_init_cron = new Document("cron.conf", f_etc_init);	//f_etc_init
	
	std::cout << "etc folder contents:  ";
	f_etc->list();

	std::cout << "init folder contents:  ";
	f_etc_init->list();

	std::cout << "Move file from init folder to bin folder\n";
	f_etc_init_cron->move("cron.conf", f_bin);

	std::cout << "bin folder contents:  ";
	f_bin->list();

	std::cout << "init folder contents:  ";
	f_etc_init->list();

	// Move a directory
	std::cout << "Move usr folder to etc folder\n";
	f_usr->move("usr",f_etc);
	// List contents of /etc
	// Should print (order and whitespaces can be different):
	// foo bar usr/
	std::cout << "etc folder contents:  ";
	f_etc->list();

	std::cout << "Root folder contents:  ";
	root->list();

	// Delete a folder (and all its children)
	delete f_etc_init;
	std::cout << "Init folder deleted!\n";
	std::cout << "etc folder contents:  ";
	f_etc->list();
	//f_etc_init->list();

	std::cout << "Create a softlink to etc folder:  ";
	Softlink *f_etc_dup = new Softlink("foo.ln", f_etc, f_usr);
	f_usr->list();
	std::cout << "Softlinks contents:  ";
	f_etc_dup->list();

	delete (f_etc_bar);
	delete (f_etc_foo);

	return 0;
}
