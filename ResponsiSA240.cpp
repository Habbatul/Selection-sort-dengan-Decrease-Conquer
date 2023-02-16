//Dibuat oleh Habbatul Qolbi H-2000018240
#include <conio.h>
#include <cstdlib>
#include <iostream>
using namespace std;

//struct untuk memudahkan pengelompokan data
typedef struct data{
	int nim;
	string nama;
	float tugas, uts, uas, total;
}data;

//fungsi untuk input data
void input_data(data *A, int n){
	//proses input dan baca data
	for (int i = 0; i < n; i++){
		cout <<"Masukkan NIM siswa ke- " << i + 1 <<" : ";
		cin >> A[i].nim;
		cout <<"Masukkan Nama siswa ke- " << i + 1 <<" : ";
		cin.ignore();getline(cin, A[i].nama);
		cout <<"Masukkan Nilai Tugas siswa ke- " << i + 1 <<" : ";
		cin >> A[i].tugas;
		cout <<"Masukkan Nilai UTS siswa ke- " << i + 1 <<" : ";
		cin >> A[i].uts;
		cout <<"Masukkan Nilai UAS siswa ke- " << i + 1 <<" : ";
		cin >> A[i].uas;
		//nilai akhir pada kasus = 20% x nTugas + 30% x nUTS + 50% x nUAS
		A[i].total =(20*A[i].tugas/100)+(30*A[i].uts/100)+(50*A[i].uas/100);
		cout <<"Nilai Akhir Keseluruhan siswa ke- " << i + 1 <<" : ";
		cout << A[i].total;
		cout<<"\n=======================================================\n";
	}
}

//fungsi untuk mencetak data
void cetak_data(data *A, int n){
	//cetak data
	for (int k = 0; k < n; k++) {
		cout<<"==================================\n";
		cout<< "||NIM \t\t: "<<A[k].nim<<"\t\t||"<<endl;
		cout<< "||Nama \t\t: "<<A[k].nama<<"\t||"<<endl;
		cout<< "||Nilai Tugas \t: "<<A[k].tugas<<"\t\t||"<<endl;
		cout<< "||Nilai UTS \t: "<<A[k].uts<<"\t\t||"<<endl;
		cout<< "||Nilai UAS \t: "<<A[k].uas<<"\t\t||"<<endl;
		cout<< "||Nilai Akhir \t: "<<A[k].total<<"\t\t||"<<endl;
		cout<<"==================================\n";
	}
	cout<<endl;
}

//fungsi untuk cetak nilai dan NIM
void cetak_ranking(data *A, int n){
	//cetak data
	for (int k = 0; k < n; k++) {
		cout<<"=================================\n";
		cout<< "||NIM \t\t: "<<A[k].nim<<"\t\t||"<<endl;
		cout<< "||Nama \t\t: "<<A[k].nama<<"\t||"<<endl;
		cout<< "||Nilai Akhir \t: "<<A[k].total<<"\t\t||"<<endl;
		cout<<"=================================\n";
	}
	cout<<endl;
}

/*tukar data adalah fungsi yang diperlukan
dalam algoritma selection sort Decrease & Conquer*/
void tukar_data(data *siswaA, data *siswaB) {
	//tukar data
	data wadah;
	wadah = *siswaA; *siswaA = *siswaB; *siswaB = wadah;
}

/*fungsi minimumNIM(), maksimumNIM, minimumNilai(), maksimumNilai
adalah fungsi yang diperlukan untuk mendapatkan nilai minimum atau
maksimum untuk ditempatkan dalam posisi depan untuk sorting. 
Fungsi ini digunakan dalam algoritma selection sort Decrease & Conquer*/

//===>SELECTION SORT NIM ASCENDING
//untuk mengurutkan nim Ascending (kecil->besar)
void minimumNIM(data *A, int dari, int n, int *tempat) {
	data min;
	min = A[dari]; *tempat = dari;
	//ini yang menunjukkan decrease
	for (int i = dari + 1; i < n; i++)
		if (A[i].nim < min.nim) {
			min = A[i]; *tempat = i;
		}
}
//algoritma selection sort dengan fungsi min dan tukar_data
void selection_sort_nimASC(data *A, int n) {
	// sellection sort
	int t;
	for (int i = 0; i < n; i++) {
		//mencari nilai minimum saat ini
		minimumNIM(A, i, n, &t);
		/*menukar urutan data pada indeks saat ini
		dengan data terkecil pada deret*/
		tukar_data(&A[i], &A[t]);
	}
}

//===>SELECTION SORT NIM DESCENDING
//untuk mengurutkan nim Descending (besar->kecil)
void maksimumNIM(data *A, int dari, int n, int *tempat) {
	int i;
	data max;
	max = A[dari]; *tempat = dari;
	for (i = dari + 1; i < n; i++)
		if (A[i].nim > max.nim) {
			max = A[i]; *tempat = i;
		}
}
//algoritma selection sort dengan fungsi max dana tukar_data 
void selection_sort_nimDESC(data *A, int n) {
	// sellection sort
	int t;
	for (int i = 0; i < n; i++) {
		maksimumNIM(A, i, n, &t);
		tukar_data(&A[i], &A[t]);
	}
}


//===>SELECTION SORT NILAI ASCENDING
//untuk mengurutkan nilai Ascending (besar->kecil)
void minimumNilai(data *A, int dari, int n, int *tempat) {
	int i;
	data min;
	min = A[dari]; *tempat = dari;
	for (i = dari + 1; i < n; i++)
		if (A[i].total < min.total) {
			min = A[i]; *tempat = i;
		}
}
//algoritma selection sort dengan fungsi min dan tukar_data
void selection_sort_nilaiASC(data *A, int n) {
	// sellection sort
	int t;
	for (int i = 0; i < n; i++) {
		minimumNilai(A, i, n, &t);
		tukar_data(&A[i], &A[t]);
	}
}

//===>SELECTION SORT NILAI Descending
//untuk mengurutkan nilai Descending (besar->kecil)
void maksimumNilai(data *A, int dari, int n, int *tempat) {
	int i;
	data min;
	min = A[dari]; *tempat = dari;
	for (i = dari + 1; i < n; i++)
		if (A[i].total > min.total) {
			min = A[i]; *tempat = i;
		}
}
//algoritma selection sort dengan fungsi min dan tukar_data
void selection_sort_nilaiDESC(data *A, int n) {
	// sellection sort
	int t;
	for (int i = 0; i < n; i++) {
		maksimumNilai(A, i, n, &t);
		tukar_data(&A[i], &A[t]);
	}
}

//===>SELECTION SORT Nama a->z
//untuk mengurutkan nama (a->z), a adalah size terkecil dalam char
void minimumNama(data *A, int dari, int n, int *tempat) {
	data min;
	min.nama="0";//tempat pembanding
	min = A[dari]; *tempat = dari;
	for (int i = dari + 1; i < n; i++)
		if (A[i].nama < min.nama) {
			min = A[i]; *tempat = i;
		}
}

//algoritma selection sort dengan fungsi min dan tukar_data
void selection_sort_name(data *A, int n) {
	// sellection sort
	int t;
	for (int i = 0; i < n; i++) {
		minimumNama(A, i, n, &t);
		tukar_data(&A[i], &A[t]);
	}
}


int main(){
	int jmlh,nim, ketemu=0;
	char pilih;
	//merge sort
	cout <<"Responsi Habbatul Qolbi H (2000018240) : Decrease & Conquer (Materi 4 Praktikum)";
	cout <<"\n\t=======================================\nMasukan Jumlah data siswa : ";
	cin >> jmlh;
	data siswa[jmlh];
	input_data(siswa, jmlh);
	getch();
	while(1){
		system("cls");
		cout <<"Data yang anda masukan : \n";
		cetak_data(siswa, jmlh);
		cout <<"Fitur :\n1. Mengurutkan berdasarkan NIM (Ascending) : Selection Sort dengan Decrease & Conquer\n";
		cout<<"2. Mengurutkan berdasarkan NIM (Descending) : Selection Sort dengan Decrease & Conquer\n";
		cout<<"3. Ranking berdasarkan Nilai (Ascending) : Selection Sort dengan Decrease & Conquer\n";
		cout<<"4. Ranking berdasarkan Nilai (Descending) : Selection Sort dengan Decrease & Conquer\n";
		cout<<"5. Mengurutkan berdasar nama (A->Z) : Selection Sort dengan Decrease & Conquer\n";
		cout<<"Pilihan anda : ";cin>>pilih;
		switch (pilih) {
			case '1': //berdasar NIM rendah->tinggi
				system("cls");
				selection_sort_nimASC(siswa, jmlh);
				cout <<"Setelah NIM diurutkan Ascending (Selection Sort dengan Decrease & Conquer) : \n";
				cetak_data(siswa, jmlh);
				cout <<endl; 
				cout<<"\nTekan enter untuk kembali memilih fitur!";
				getch();break;
			case '2': //berdasar NIM tinggi->rendah
				system("cls");
				selection_sort_nimDESC(siswa, jmlh);
				cout <<"Setelah NIM diurutkan Descending (Selection Sort dengan Decrease & Conquer) : \n";
				cetak_data(siswa, jmlh);
				cout <<endl; 
				cout<<"\nTekan enter untuk kembali memilih fitur!";
				getch();break;
			case '3': //berdasar Nilai Total rendah->tinggi
				system("cls");
				selection_sort_nilaiASC(siswa, jmlh);
				cout <<"Setelah diurutkan Ascending berdasar Total Nilai (Selection Sort dengan Decrease & Conquer) : \n";
				cetak_ranking(siswa, jmlh);
				cout <<endl; 
				cout<<"\nTekan enter untuk kembali memilih fitur!";
				getch();break;
			case '4': //berdasar Nilai Total rendah->tinggi
				system("cls");
				selection_sort_nilaiDESC(siswa, jmlh);
				cout <<"Setelah diurutkan Descending berdasar Total Nilai (Selection Sort dengan Decrease & Conquer) : \n";
				cetak_ranking(siswa, jmlh);
				cout <<endl; 
				cout<<"\nTekan enter untuk kembali memilih fitur!";
				getch();break;
			case '5': //berdasar Nilai Total rendah->tinggi
				system("cls");
				selection_sort_name(siswa, jmlh);
				cout <<"Setelah diurutkan berdasar nama dari A->Z (Selection Sort dengan Decrease & Conquer) : \n";
				cetak_data(siswa, jmlh);
				cout <<endl; 
				cout<<"\nTekan enter untuk kembali memilih fitur!";
				getch();break;
			default: cout <<"Klik pilihan yang ada!\n";getch();
		}
	}
}
