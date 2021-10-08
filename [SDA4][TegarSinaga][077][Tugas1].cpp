#include<conio.h>
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<cstdlib>

#define nmax 20

using namespace std;

int n=0; // deklarasi nilai n sebanyak 0

struct data{ // deklarasi sebuah struct dengan nama 'data'.
    int nim;
    char nama[20];
    char kom;
};

struct data maba[nmax]; // deklarasi variabel 'maba' dengan tipe data struct dari struct 'data' dengan maksimal alokasi memori
                        // sebanyak nmax.

void tambah_data();
void hapus_data();
void bersihkan_data();
void update_data();
void swap_data();
void sisip_data();
void tampilkan_data();

main()
{
      int pil;
	  menu :cout<<" \t\tMENU \n";
      cout<<"1. tambah data\n";
      cout<<"2. hapus data \n";
      cout<<"3. bersihkan data \n";
      cout<<"4. update data \n";
      cout<<"5. swap data \n";
      cout<<"6. sisip data \n";
      cout<<"7. tampilkan data \n";
      cout<<"8. keluar \n";
	  cout<<"\npilih menu (1/2/3/4/5/6/7/8) ? ";
      cin>>pil;
      ulang:if (pil==1)tambah_data();
      	else if (pil==2) hapus_data();
      	else if (pil==3) bersihkan_data();
      	else if (pil==4) update_data();
      	else if (pil==5) swap_data();
      	else if (pil==6) sisip_data();
      	else if (pil==7) tampilkan_data();
      	else if (pil==8) exit(1);
      	else {
           cout<<"pilihan tak tersedia...!!!\n";
           goto ulang;
      }
      goto menu;
   	getch();
}

void tambah_data(){
     if (n<nmax){
        cout<<"nama : ";
        cin>>maba[n].nama;
		cout<<"NIM : ";
        cin>>maba[n].nim;
        cout<<"Kom : ";
        cin>>maba[n].kom;
        n++;
        }
     else cout<<"data telah melebihi...!!!\nmaksimal data = "<<nmax;
}

void hapus_data(){
     int x;
     cout<<"pilih data yang akan dihapus (1 s.d. 20) : ";
     cin>>x;
     if (x<n && x>0){
        for (int i=x;i<n;i++){
            strcpy(maba[x-1].nama,maba[x].nama);
            maba[x-1].nim = maba[x].nim;
            maba[x-1].kom = maba[x].kom;
            x++;
            }
        n--;
        }
     else if(x==n) n--;
     else cout<<"data yang ingin dihapus tidak ada...!!!\n";
}
void bersihkan_data(){
	cout<<"Data Anda telah dihapus semua";
	n=0;
}

void update_data(){
	int x;
	cout<<"Masukkan Data yang ingin Diupdate : ";
	cin>>x;
	cout<<"\nNama: ";cin>>maba[x-1].nama;
	cout<<"\nNim: ";cin>>maba[x-1].nim;
	cout<<"\nKom: ";cin>>maba[x-1].kom;
}
void swap_data(){
	data temp;
	int x,y;
	cout<<"Masukkan Data ke 1 yang ingin diswap : ";
	cin>>x;
	cout<<"Masukkan Data ke 2 yang ingin diswap : ";
	cin>>y;
	temp=maba[x-1];
	maba[x-1]=maba[y-1];
	maba[y-1]=temp;
	cout<<"Data telah berhasil diswap"<<endl;
	
}
void sisip_data(){
	int x;
	cout<<"Pilih data yang akan disisip : ";
	cin>>x;
	for(int i=n-1;i>1;i--){
		strcpy(maba[i+1].nama,maba[i].nama);
		maba[i+1].nim=maba[i].nim;
		maba[i+1].kom=maba[i].kom;
	}
	n++;
	cout<<"Nama : ";
	cin>>maba[x-1].nama;
	cout<<"NIM : ";
	cin>>maba[x-1].nim;
	cout<<"KOM : ";
	cin>>maba[x-1].kom;
	cout<<"Data telah ditambahkan "<<endl;
}
void tampilkan_data(){
     if (n==0) cout<<"Tidak Ada data yang disimpan...!!!\n";
     else {
          for (int i=0;i<n;i++){
              cout<<"Data ke-"<<i+1<<" : ";
              cout<<"\nNama : "<<maba[i].nama;
              cout<<"\nNIM  : "<<maba[i].nim;
              cout<<"\nKom  : "<<maba[i].kom;
              cout<<endl;
              }
     }
}

