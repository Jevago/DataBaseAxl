//
//  main.cpp
//  DataBase
//
//  Created by Jonathan Emmanuell Vázquez González on 06/06/21.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>

#define ASCENDENTE 0u
#define DESENDENTE 1u

typedef struct Informacion
{
    std::string artista;
    int numTracks;
    float calificacion;
} Informacion;

typedef struct Album
{
    std::string nombre;
    Informacion info;
}Album;

class Disco
{
private:
    int id_key;
    Album *cd;
    
public:
    Disco()
    {
        cd = new Album;
    }
    
    ~Disco()
    {
        delete cd;
    }
    
    int GetIdKey(void)
    {
        return id_key;
    }
    
    void SetIdKey(int id)
    {
        this->id_key = id;
    }
    
    Album *GetCD(void)
    {
        return cd;
    }
    
    void SetCD(Album *_cd)
    {
        cd->nombre = _cd->nombre;
        cd->info.artista = _cd->info.artista;
        cd->info.calificacion = _cd->info.calificacion;
        cd->info.numTracks = _cd->info.numTracks;
    }
    
    void SetInfo(int _id, Album *_cd)
    {
        SetIdKey(_id);
        SetCD(_cd);
    }
};

class Database
{
private:
    int size;
    Disco *data;

public:
    Database()
    {
        size = 0;
        data = NULL;
    }
    
    ~Database()
    {
        delete [] data;
        data = NULL;
        size = 0;
    }
    
    int GetSize(void)
    {
        return  size;
    }
    
    void SetSize(int _size)
    {
        size = _size;
    }
    
    void ReservarMemoria(void)
    {
        data = new Disco [size];
    }
    
    void Escribir(void);
    void Mostrar(void);
    void OrdenarNumericamente(unsigned char type);
    void OrdenarNumDesendente(void);
    void OrdenarNumAsendente(void);
    void OrdenarAlfabeticamente(void);
    
};

void Database::Escribir(void)
{
    int i = 0;
    Album aux;
    
    for(i = 0; i < this->size; i++)
    {
        std::cout << "Nombre del album: ";
        std::cin >> aux.nombre;
        
        std::cout << "Nombre del artista: ";
        std::cin >> aux.info.artista;
        
        std::cout << "Nombre del numero de tracks: ";
        std::cin >> aux.info.numTracks;
        
        std::cout << "Nombre del calificacion: ";
        std::cin >> aux.info.calificacion;
        
        this->data[i].SetIdKey(i);
        this->data[i].SetCD(&aux);
        
        std::cout << "*******************************************************************" << std::endl;
    }
}

void Database::Mostrar(void)
{
    int i = 0;
    Album *aux = NULL;
    
    for(i = 0; i < this->size; i++)
    {
        std::cout << "ID database: " << this->data[i].GetIdKey() << std::endl;
        aux = this->data[i].GetCD();
        
        std::cout << "Nombre del album: " << aux->nombre << std::endl;
        std::cout << "Nombre del artista: " << aux->info.artista << std::endl;
        std::cout << "Nombre del calification: " << aux->info.calificacion << std::endl;
        std::cout << "Nombre del numero de pistas: " << aux->info.numTracks << std::endl;
        
        std::cout << "*******************************************************************" << std::endl;
    }
}

void Database::OrdenarNumDesendente(void)
{
    int i = 0;
    int j = 0;
    int idi = 0;
    int idj = 0;
    int idaux = 0;
    Album *aux = NULL;
    Album ax2;
    
    std::cout << "\n\ntamanio: " << this->size << std::endl;

    for(i = 0; i < this->size - 1; i++)
    {
        idi = data[i].GetIdKey();
        for(j = i + 1; j < this->size; j++)
        {
            idj = data[j].GetIdKey();
            
            if(idi < idj)
            {
                std::cout << "Ordenando Elementos!!!!!" << std::endl;
                idaux = idi;
                idi = idj;
                idj = idaux;
                
                data[i].SetIdKey(idi);
                data[j].SetIdKey(idj);
                
                aux = data[i].GetCD();
                
                ax2.nombre = aux->nombre;
                ax2.info.artista = aux->info.artista;
                ax2.info.calificacion = aux->info.calificacion;
                ax2.info.numTracks = aux->info.numTracks;
                
                data[i].SetCD(data[j].GetCD());
                data[j].SetCD(&ax2);
            }
            else
            {
                std::cout << "Elemento bien posicionado!!!!!" << std::endl;
            }
        }
    }
}

void Database::OrdenarNumAsendente(void)
{
    
}

void Database::OrdenarNumericamente(unsigned char type)
{
    switch (type) {
        case ASCENDENTE:
            OrdenarNumAsendente();
            break;
        case DESENDENTE:
            OrdenarNumDesendente();
            break;
            
        default:
            std::cout << "Ordenamiento no soportado!!!" << std::endl;
            break;
    }
}


int main(int argc, const char * argv[]) {
    int size = 0;
    Database db;
    
    std::cout << "Database size: " << db.GetSize() << std::endl;
    std::cout << "Ingrese el total de datos: ";
    std::cin >> size;
    
    db.SetSize(size);
    db.ReservarMemoria();
    
    std::cout << "Database size: " << db.GetSize() << std::endl;
    
    db.Escribir();
    std::cout << "---------------------------------------------------------------------" << std::endl;
    db.Mostrar();
    std::cout << "---------------------------------------------------------------------" << std::endl;
    std::cout << "---------------------------- Ordenamiento ---------------------------" << std::endl;
    //db.OrdenarNumericamente(DESENDENTE);
    db.OrdenarNumDesendente();
    std::cout << "---------------------------------------------------------------------" << std::endl;
    db.Mostrar();
    
    std::cout << "Hello, World!\n";
    return 0;
}
