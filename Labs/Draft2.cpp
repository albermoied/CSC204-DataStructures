#include<iostream>
#include<conio.h>

using namespace std;

class FileNode
{
      private:
              string content;
              FileNode* next;
      public:
             FileNode()
             {
               content="";
               next=NULL;
             }
             FileNode(string c)
             {
              content=c;
              next=NULL;
             }
             FileNode* getNext()
             {
                  return next;
             }
             void setNext(FileNode* n)
             {
                  next=n;
             }
             string getContent()
             {
                  return content;
             }
             void setContent(string c)
             {
                  content=c;
             }
             void display()
             {
                  cout<<content<<"   ";
             }
};

class FolderNode
{
      private:
              FolderNode* prev;
              FolderNode* sub;
              FolderNode* next;
              FileNode* file;
              string name;
      public:
             FolderNode()
             {
                  name="";
                  sub = NULL;
                  next = NULL;
                  file = NULL;
                  prev = NULL;       
             }
             FolderNode(string n)
             {
                  name=n;
                  sub=NULL;
                  next=NULL;
                  file=NULL;
                  prev=NULL;
             }
             string getName()
             {
                  return name;
             }
             void setName(string n)
             {
                  name=n;
             }
             FolderNode *& getSub()
             {
                  return sub;
             }
             void setSub(FolderNode* s)
             {
                  sub = s;
             }
             FolderNode *& getPrev()
             {
                  return prev;
             }
             void setPrev(FolderNode* p)
             {
                  prev = p;
             }
             FolderNode *& getNext()
             {
                  return next;
             }
             void setNext(FolderNode* n)
             {
                  next = n;
             }
             FileNode* getFile()
             {
                  return file;
             }
             void setFile(FileNode* f)
             {
                  file = f;
             }
             void display()
             {
                  if(prev!=NULL)
                  {
                                cout<<"Prev: "<<prev->getName()<<endl;
                  }
                  cout<<"Name: "<<name<<endl;
                  if(sub!=NULL)
                  {
                               cout<<"Sub: "<<sub->getName()<<endl;
                  }
                  if(next!=NULL)
                  {
                                cout<<"Next: ";
                                FolderNode* curr=next;
                                while(curr!=NULL)
                                {
                                                 cout<<curr->getName()<<"   ";
                                                 curr=curr->getNext();
                                }
                                cout<<endl;
                  }
                  if(file!=NULL)
                  {
                                cout<<"Files: ";
                                FileNode* cur=file;
                                while(cur!=NULL)
                                {
                                                cur->display();
                                                cur=cur->getNext();
                                }
                                cout<<endl;
                  }
             }
                   
};

class FList
{
      private:
              FolderNode* root;
      public:
             FList()
             {
                    root= new FolderNode("Comp");
             }
             void insertFolder(FolderNode*& r, string n)
             {
                  FolderNode* f= new FolderNode(n);
                  bool a;
                  cout<<"Sub(0) or Next(1)"<<endl;
                  cin>>a;
                  if(a==0)
                  {
                          r->setSub(f);
                          f->setPrev(r);
                  }
                  else if(a==1)
                  {
                       r->setNext(f);
                       f->setPrev(r);
                  }
             }
             /*void deleteFolder(FolderNode*& r)
             {
                  bool a;
                  cout<<"Sub(0) or Next(1)"<<endl;
                  cin>>a;
                  if(a==0)
                  {
                          if(r->getSub()!=NULL)
                          {
                                               FolderNode* curr=r->getSub();
                                               curr->setPrev(NULL);
                                               r->setSub(NULL);
                          }
                  }
                  if(a==1)
                  {
                          if(r->setNext()!=NULL)
                          {
                                                FolderNode* curr=r->getNext();
                                                r->setNext(curr->getNext());
                                                curr->getNext()->setPrev(r);
                                                delete curr;
                          }
                  }
             }*/
             void insertFile(FolderNode*& r, string n)
             {
                  FileNode* f = new FileNode(n);
                  if(r->getFile()==NULL)
                  {
                                        r->setFile(f);
                  }
                  else
                  {
                      FileNode* curr=r->getFile();
                      while(curr->getNext()!=NULL)
                      {
                                                  curr=curr->getNext();
                      }
                      curr->setNext(f);
                  }
             }
             FolderNode*& getRoot()
             {
                  return root;
             }
};

void explorer(FList f, FolderNode*& root);

int main()
{
    FList a;
    explorer(a, a.getRoot());
    getch();
    return 0;
}


void explorer(FList f, FolderNode*& root)
{
     system("cls");
     root->display();
     cout<<endl;
     int opt;
     cout<<"Go To Sub(1)"<<endl;
     cout<<"Go To Next(2)"<<endl;
     cout<<"Insert(3)"<<endl;
     cout<<"Go To Previous(4)"<<endl;
     cout<<"Close Program(0)"<<endl;
     cin>>opt;
     switch(opt)
     {
         case 0:
              cout<<"Closing..."<<endl;
              break;
         case 1:
              if(r->getSub()!=NULL)
              {
                                   explorer(f, root->getSub());
              }
              else
              {
                  explorer(f,root);
              }
              break;
         case 2:
              if(r->getNext()!=NULL)
              {
                                    explorer(f, root->getNext());
              }
              else
              {
                  explorer(f,root);
              }
              break;
         case 3:
              bool i;
              cout<<"File(0) or Folder(1)"<<endl;
              cin>>i;
              if(i==0)
              {
                      string finame;
                      cout<<"File name: ";
                      cin>>finame;
                      f.insertFile(root, finame);
                      explorer(f, root);
                      break;
              }
              else if(i==1)
              {
                   string foname;
                   cout<<"Folder name: ";
                   cin>>foname;
                   f.insertFolder(root, foname);
                   explorer(f, root);
                   break;
              }
         case 4:
              explorer(f, root->getPrev());
              break;
         case 5:
              bool i;
              cout<<"File(0) or Folder(1)"<<endl;
              cin>>i;
              if(i==0)
              {
                      explorer(f, root);
                      break;
              }
              else if(i==1)
              {
                   f.deleteFolder(root);
                   explorer(f, root);
                   break;
              }
         default:
                 cout<<"Invalid option."<<endl;
                 explorer(f,root);
     }
}
