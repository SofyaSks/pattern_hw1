#include <iostream>
#include <vector>
using namespace std;



class Document
{
public:
    virtual void info() = 0;
    virtual ~Document() {}
};

class DocTxt : public Document{
    void info() {
        cout << "Doc.txt" << endl;
    }
};

class DocExe : public Document{
    void info() {
        cout << "Doc.exe" << endl;
    }
};

class DocPdf : public Document {
    void info() {
        cout << "Doc.pdf" << endl;
    }
};

class Redactor : public DocTxt, public DocExe, public DocPdf {
    void createDoc()  {
        cout << "Document created" << endl;
    }

    void openDoc() {
        cout << "Document opened" << endl;
    }

    void saveDoc() {
        cout << "Document saved" << endl;
    }

    void newNameDoc() {
        cout << "Document name changed" << endl;
    }

    void printDoc() {
        cout << "Document printed" << endl;
    }

    void closeDoc() {
        cout << "Document closed" << endl;
    }
};

// Фабрики объектов
class Factory
{
public:
    virtual Document* createDocument() = 0;
    virtual ~Factory() {}
};

class DocTxtFactory : public Factory
{
public:
   Document* createDocument() {
        return new DocTxt;
    }
};

class DocExeFactory : public Factory
{
public:
    Document* createDocument() {
        return new DocExe;
    }
};

class DocPdfFactory : public Factory
{
public:
    Document* createDocument() {
        return new DocPdf;
    }
};



int main()
{
    DocTxtFactory* doctxt_factory = new DocTxtFactory;
    DocExeFactory* docexe_factory = new DocExeFactory;
    DocPdfFactory* docpdf_factory = new DocPdfFactory;

    vector<Document*> v;
    v.push_back(doctxt_factory->createDocument());
    v.push_back(docexe_factory->createDocument());
    v.push_back(docpdf_factory->createDocument());

    for (int i = 0; i < v.size(); i++)
        v[i]->info();
   
}