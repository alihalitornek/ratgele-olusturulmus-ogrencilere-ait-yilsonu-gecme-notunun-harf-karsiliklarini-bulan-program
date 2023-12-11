/****************************************************************************
**					         
**			        
**				         
**				            
**
**				        
**				       
**				       
**				       
****************************************************************************/


#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{

    //buyuknot = 0 ve ortalamalarınbuyuknot = 0 çünkü gitgide büyüyecek ve enbüyük not bulunacak kucuknot = 100 ve ortalamalarınkucuknot = 100 çünkü gitgide küçülecek ve enküçük not bulunacak (satır 246 ve 256)
    //AAsayisi,ortalamalarınAAsayisi ve digerlerine 0 atandı çünkü bünlar sayac olarak kullanılacak (satır 155 ve 203)
    struct Ogrenci
    {
        float ogrencinotortalamalaritoplami = 0, buyuknot = 0, kucuknot = 100, ortalamalarınbuyuknot = 0, ortalamalarınkucuknot = 100, standartsapma;
        int vizeagirlik, odevagirlik, kisasinavagirlik, yiliciagirlik, finalagirlik, ogrencisayisi, sinavsayisi, AAsayisi = 0, BAsayisi = 0, BBsayisi = 0, CBsayisi = 0, CCsayisi = 0, DCsayisi = 0, DDsayisi = 0, FDsayisi = 0, FFsayisi = 0, ortalamalarınAAsayisi = 0, ortalamalarınBAsayisi = 0, ortalamalarınBBsayisi = 0, ortalamalarınCBsayisi = 0, ortalamalarınCCsayisi = 0, ortalamalarınDCsayisi = 0, ortalamalarınDDsayisi = 0, ortalamalarınFDsayisi = 0, ortalamalarınFFsayisi = 0;
        string isim[49] = { "Ahmet", "Mehmet", "Ali", "Ayse", "Fatma", "Huseyin", "Hasan", "Burak", "Ceren", "Deniz", "Emre", "Elif", "Gizem", "Cem", "Ceren", "Berk", "Aylin", "Derya", "Elanur", "Emir", "Firat", "Efe", "Begum", "Bahar", "Ayberk", "Gokhan", "Doruk", "Deniz", "Cem", "Cansu", "Bilge", "Berna", "Beril", "Eren", "Cenk", "Ezgi", "Can", "Ceyda", "Buse", "Defne", "Dilan", "Ekin", "Emine", "Eda", "Furkan", "Gizem", "Duygu", "Egemen", "Beyza" };
        string soyisim[49] = { "Yilmaz", "Kaya", "Demir", "Celik", "Yildirim", "Sahin", "Polat", "Aydin", "Yavuz", "Aslan", "Ozturk", "Koc", "Erdogan", "Ozdemir", "Arslan", "Yilmaz", "Ozkan", "Keskin", "Tas", "Kilic", "Uzun", "Eroglu", "Alkan", "Karadag", "Erdogan", "Cetin", "Simsek", "Kurt", "Acar", "Turan", "Kaplan", "Gunes", "Oguz", "Sen", "Sari", "Kilic", "Ozdogan", "Atalay", "Balaban", "Eren", "Gunduz", "Buyukkaya", "Yildiz", "Gur", "Guven", "Kose", "Yalcin", "Akyuz", "Genc" };



    }ogrencibilgi;

    srand(time(0));//Bu fonksiyonu rand() foksiyonunun aynı değerleri üretmemesi için kullanıyoruz

    //ogrencisayisi negatif olmamalı
    while (ogrencibilgi.ogrencisayisi <= 0)
    {
        cout << "lutfen ogrenci sayisini girin :";
        cin >> ogrencibilgi.ogrencisayisi;
    }
    //ogrecisayisi ve sinavsayisini elde ediyoruz herbir öğrenci için 6 sınav var
    ogrencibilgi.sinavsayisi = 6 * ogrencibilgi.ogrencisayisi;

    //bize gelen ogrencisayisi parametresine göre dinamik bir hafıza oluşturuyoruz
    int* vize = (int*)malloc(ogrencibilgi.sinavsayisi * sizeof(int));
    int* odev1 = (int*)malloc(ogrencibilgi.sinavsayisi * sizeof(int));
    int* odev2 = (int*)malloc(ogrencibilgi.sinavsayisi * sizeof(int));
    int* kisasinav1 = (int*)malloc(ogrencibilgi.sinavsayisi * sizeof(int));
    int* kisasinav2 = (int*)malloc(ogrencibilgi.sinavsayisi * sizeof(int));
    int* yilicisinav = (int*)malloc(ogrencibilgi.sinavsayisi * sizeof(int));
    int* finalnot = (int*)malloc(ogrencibilgi.sinavsayisi * sizeof(int));
    int* ogrencinotlari = (int*)malloc(ogrencibilgi.sinavsayisi * sizeof(int));
    int* ogrencinotortalamalari = (int*)malloc(ogrencibilgi.sinavsayisi * sizeof(int));

    //dinamik bir şekilde ismim+soyisimi tutan bir string elde ediyoruz (satır 72)
    string* tumisim = new string[ogrencibilgi.sinavsayisi];

    //2 farklı rastgele sayı üretip bunlar sayesinde rastgele bir isim ve rastgele bir soyisim elde edip bunları birleştirerek tumisim dizisi elde ediyoruz öğrenci sayısı kadar tumisim olmalı
    //%49 almamızın sebebi string isim[] ve string soyisim[](0 ile 48 arası sayı dönecek)
    int* rastgelesayiisimicin = (int*)malloc(ogrencibilgi.ogrencisayisi * sizeof(int));
    int* rastgelesayisoyisimicin = (int*)malloc(ogrencibilgi.ogrencisayisi * sizeof(int));
    for (int sayac = 0;sayac < ogrencibilgi.ogrencisayisi;sayac++)
    {
        rastgelesayiisimicin[sayac] = rand();
        rastgelesayiisimicin[sayac] = rastgelesayiisimicin[sayac] % 49;

        rastgelesayisoyisimicin[sayac] = rand();
        rastgelesayisoyisimicin[sayac] = rastgelesayisoyisimicin[sayac] % 49;


        tumisim[sayac] = ogrencibilgi.isim[rastgelesayiisimicin[sayac]] + " " + ogrencibilgi.soyisim[rastgelesayisoyisimicin[sayac]];
    }

    /*Burada ogrencinotlari dizisinin ilk % 20lik kısmı için 100 - 80 arası ve ondansonraki % 50lik kısmı için 79 - 50 arası ve son %30luk kısmı için 49 - 0 arası rastgele sayı üretiyor.
    Bu işlemler sinavsayisi değerine göre atanıyor ve toplamda sinavsayisi kadar ogrencinotlari dizisinde eleman tutuluyor (kısaca diziyi 3 ana parçaya ayırıyoruz) */
    for (int sayac = 1;sayac <= roundf(ogrencibilgi.sinavsayisi * 0.2);sayac++)
    {
        ogrencinotlari[sayac] = rand() % 21 + 80;
    }
    for (int sayac = roundf(ogrencibilgi.sinavsayisi * 0.2 + 1);sayac <= roundf(ogrencibilgi.sinavsayisi * 0.5 + ogrencibilgi.sinavsayisi * 0.2);sayac++)
    {
        ogrencinotlari[sayac] = rand() % 30 + 50;
    }
    for (int sayac = roundf(ogrencibilgi.sinavsayisi * 0.5 + ogrencibilgi.sinavsayisi * 0.2 + 1);sayac <= roundf(ogrencibilgi.sinavsayisi * 0.5 + ogrencibilgi.sinavsayisi * 0.2 + ogrencibilgi.sinavsayisi * 0.3);sayac++)
    {
        ogrencinotlari[sayac] = rand() % 50;
    }
    //Dışardan vize ağırlığı, ödev ağırlığı, kısasınav ağırlığı, yıliçi ağırlığı ve final ağırlığı verilerini alıyoruz
    //Kullanıcının 0 ile 100 arası sayı girmeli ve (vizeağırlık + 2* ksasınavağırlık + 2* ödevagırlık) 100e eşitolmalı ve aynı zmanda (yıliçiağılık + finalfinal) notu 100 olmalı
    while ((ogrencibilgi.vizeagirlik < 0 || ogrencibilgi.odevagirlik < 0 || ogrencibilgi.kisasinavagirlik < 0 || ogrencibilgi.yiliciagirlik < 0 || ogrencibilgi.finalagirlik < 0 || 100 < ogrencibilgi.vizeagirlik || 100 < ogrencibilgi.odevagirlik || 100 < ogrencibilgi.kisasinavagirlik || 100 < ogrencibilgi.yiliciagirlik || 100 < ogrencibilgi.finalagirlik) || (100 != ogrencibilgi.vizeagirlik + 2 * ogrencibilgi.odevagirlik + 2 * ogrencibilgi.kisasinavagirlik) || (100 != ogrencibilgi.yiliciagirlik + ogrencibilgi.finalagirlik))
    {
        cout << "lutfen vize agirligini girin(0 ile 100 arasinda) :";
        cin >> ogrencibilgi.vizeagirlik;
        cout << "lutfen odev agirligini girin(0 ile 100 arasinda) :";
        cin >> ogrencibilgi.odevagirlik;
        cout << "lutfen kisasinav agirligini girin(0 ile 100 arasinda) :";
        cin >> ogrencibilgi.kisasinavagirlik;
        cout << "lutfen yilici agirligi girin(0 ile 100 arasinda) :";
        cin >> ogrencibilgi.yiliciagirlik;
        cout << "lutfen final agirligini girin(0 ile 100 arasinda) :";
        cin >> ogrencibilgi.finalagirlik;
        system("cls");
    }
    system("cls");

    //Burada ogrencinotlari dizisinin elemanlarını rastgele bir biçimde yer değiştiriyoruz
    //Burada sinavsayisini 10 ile çarpmamızın özel bir sebebi yok eğer daha fazla karışmasını isteseydik daha yüksek bir sayi ile çarpabilirdik
    for (int sayac = 1;sayac <= 10 * ogrencibilgi.sinavsayisi;sayac++)
    {
        int rastgelesayi1 = (rand() % ogrencibilgi.sinavsayisi) + 1;
        int rastgelesayi2 = (rand() % ogrencibilgi.sinavsayisi) + 1;
        int ilkrastgelesayi1;
        ilkrastgelesayi1 = ogrencinotlari[rastgelesayi1];
        ogrencinotlari[rastgelesayi1] = ogrencinotlari[rastgelesayi2];
        ogrencinotlari[rastgelesayi2] = ilkrastgelesayi1;
    }

    //ogrencinotlari dizisini eşit bir şekilde 6 parçaya ayırıp bu parçaları sırasıyla vize, odev1, odev2, kisasinav1, kisasinav2 ve finalnot isimli dizilere atıyoruz
    for (int sayac = 1;sayac <= ogrencibilgi.sinavsayisi / 6;sayac++)
    {
        vize[sayac] = ogrencinotlari[sayac];

    }
    for (int sayac = ogrencibilgi.sinavsayisi / 6 + 1;sayac <= ogrencibilgi.sinavsayisi * 2 / 6;sayac++)
    {
        odev1[sayac - ogrencibilgi.sinavsayisi / 6] = ogrencinotlari[sayac];

    }
    for (int sayac = ogrencibilgi.sinavsayisi * 2 / 6 + 1;sayac <= ogrencibilgi.sinavsayisi * 3 / 6;sayac++)
    {
        odev2[sayac - ogrencibilgi.sinavsayisi * 2 / 6] = ogrencinotlari[sayac];

    }
    for (int sayac = ogrencibilgi.sinavsayisi * 3 / 6 + 1;sayac <= ogrencibilgi.sinavsayisi * 4 / 6;sayac++)
    {
        kisasinav1[sayac - ogrencibilgi.sinavsayisi * 3 / 6] = ogrencinotlari[sayac];

    }
    for (int sayac = ogrencibilgi.sinavsayisi * 4 / 6 + 1;sayac <= ogrencibilgi.sinavsayisi * 5 / 6;sayac++)
    {
        kisasinav2[sayac - ogrencibilgi.sinavsayisi * 4 / 6] = ogrencinotlari[sayac];

    }
    for (int sayac = ogrencibilgi.sinavsayisi * 5 / 6 + 1;sayac <= ogrencibilgi.sinavsayisi;sayac++)
    {
        finalnot[sayac - ogrencibilgi.sinavsayisi * 5 / 6] = ogrencinotlari[sayac];

    }

    //Örencilerin notortalamalarını hesaplıyoruz ve sayısal nota göre harf notu seçip bunları bastırıyoruz
    /*Burada ogrencibilgi.tumisim[sayac - 1] yazılmasının sebebi tumisim 0. index ile tutulmaya başlandı
    ama ogrencinotortalamalari 1. index ile tutulmaya başlandı (bunun sebebi enbaşında ogrencibilgi.ogrencinotlari[] dizisi 1. index ile tutulmaya başlandı) */
    //anızamanda ogrencibilgi.ortalamalarınAAsayisi ve diğerleri sayılıyor
    for (int sayac = 1;sayac <= ogrencibilgi.ogrencisayisi;sayac++)
    {

        ogrencinotortalamalari[sayac] = (vize[sayac] * ogrencibilgi.vizeagirlik / 100 + odev1[sayac] * ogrencibilgi.odevagirlik / 100 + odev2[sayac] * ogrencibilgi.odevagirlik / 100 + kisasinav1[sayac] * ogrencibilgi.kisasinavagirlik / 100 + kisasinav2[sayac] * ogrencibilgi.kisasinavagirlik / 100) * ogrencibilgi.yiliciagirlik / 100 + finalnot[sayac] * ogrencibilgi.finalagirlik / 100;
        cout << "ogrenci ismi :" << tumisim[sayac - 1] << " notortalamasi :" << ogrencinotortalamalari[sayac] << " vizesi :" << vize[sayac] << " odev1 :" << odev1[sayac] << " odev2 :" << odev2[sayac] << " kisasinav1 :" << kisasinav1[sayac] << " kisasinav2 :" << kisasinav2[sayac] << " finalnotu :" << finalnot[sayac] << " ortalamaya gore harf notu :";
        if (ogrencinotortalamalari[sayac] <= 100 && ogrencinotortalamalari[sayac] >= 90)
        {
            cout << "AA"; ogrencibilgi.ortalamalarınAAsayisi++;
        }
        else if (ogrencinotortalamalari[sayac] < 90 && ogrencinotortalamalari[sayac] >= 85)
        {
            cout << "BA"; ogrencibilgi.ortalamalarınBAsayisi++;
        }
        else if (ogrencinotortalamalari[sayac] < 85 && ogrencinotortalamalari[sayac] >= 80)
        {
            cout << "BB"; ogrencibilgi.ortalamalarınBBsayisi++;
        }
        else if (ogrencinotortalamalari[sayac] < 80 && ogrencinotortalamalari[sayac] >= 75)
        {
            cout << "CB"; ogrencibilgi.ortalamalarınCBsayisi++;
        }
        else if (ogrencinotortalamalari[sayac] < 75 && ogrencinotortalamalari[sayac] >= 65)
        {
            cout << "CC"; ogrencibilgi.ortalamalarınCCsayisi++;
        }
        else if (ogrencinotortalamalari[sayac] < 65 && ogrencinotortalamalari[sayac] >= 58)
        {
            cout << "DC"; ogrencibilgi.ortalamalarınDCsayisi++;
        }
        else if (ogrencinotortalamalari[sayac] < 58 && ogrencinotortalamalari[sayac] >= 50)
        {
            cout << "DD"; ogrencibilgi.ortalamalarınDDsayisi++;
        }
        else if (ogrencinotortalamalari[sayac] < 50 && ogrencinotortalamalari[sayac] >= 40)
        {
            cout << "FD"; ogrencibilgi.ortalamalarınFDsayisi++;
        }
        else if (ogrencinotortalamalari[sayac] < 40 && ogrencinotortalamalari[sayac] >= 0)
        {
            cout << "FF"; ogrencibilgi.ortalamalarınFFsayisi++;
        }
        else
        {
            cout << "Harf notu hesaplanamadi";
        }
        cout << endl;
    }
    //ogrencibilgi.AAsayisi ve diğerleri sayılıyor
    for (int sayac = 1;sayac <= ogrencibilgi.sinavsayisi;sayac++)
    {
        if (ogrencinotlari[sayac] <= 100 && ogrencinotlari[sayac] >= 90)
        {
            ogrencibilgi.AAsayisi++;
        }
        else if (ogrencinotlari[sayac] < 90 && ogrencinotlari[sayac] >= 85)
        {
            ogrencibilgi.BAsayisi++;
        }
        else if (ogrencinotlari[sayac] < 85 && ogrencinotlari[sayac] >= 80)
        {
            ogrencibilgi.BBsayisi++;
        }
        else if (ogrencinotlari[sayac] < 80 && ogrencinotlari[sayac] >= 75)
        {
            ogrencibilgi.CBsayisi++;
        }
        else if (ogrencinotlari[sayac] < 75 && ogrencinotlari[sayac] >= 65)
        {
            ogrencibilgi.CCsayisi++;
        }
        else if (ogrencinotlari[sayac] < 65 && ogrencinotlari[sayac] >= 58)
        {
            ogrencibilgi.DCsayisi++;
        }
        else if (ogrencinotlari[sayac] < 58 && ogrencinotlari[sayac] >= 50)
        {
            ogrencibilgi.DDsayisi++;
        }
        else if (ogrencinotlari[sayac] < 50 && ogrencinotlari[sayac] >= 40)
        {
            ogrencibilgi.FDsayisi++;
        }
        else if (ogrencinotlari[sayac] < 40 && ogrencinotlari[sayac] >= 0)
        {
            ogrencibilgi.FFsayisi++;
        }


    }

    //enbüyüknotortalaması ve enküçüknotortalaması tespit ediliyor
    for (int sayac = 1;sayac <= ogrencinotortalamalari[sayac];sayac++)
    {
        ogrencibilgi.ogrencinotortalamalaritoplami = ogrencibilgi.ogrencinotortalamalaritoplami + ogrencinotortalamalari[sayac];
        if (ogrencinotortalamalari[sayac] > ogrencibilgi.ortalamalarınbuyuknot)
            ogrencibilgi.ortalamalarınbuyuknot = ogrencinotortalamalari[sayac];
        if (ogrencinotortalamalari[sayac] < ogrencibilgi.ortalamalarınkucuknot)
            ogrencibilgi.ortalamalarınkucuknot = ogrencinotortalamalari[sayac];
    }

    //enbüyüknot ve enküçüknot tespit ediliyor
    for (int sayac = 1;sayac <= ogrencinotlari[sayac];sayac++)
    {
        if (ogrencinotlari[sayac] > ogrencibilgi.buyuknot)
            ogrencibilgi.buyuknot = ogrencinotlari[sayac];
        if (ogrencinotlari[sayac] < ogrencibilgi.kucuknot)
            ogrencibilgi.kucuknot = ogrencinotlari[sayac];
    }

    //burada veriler ekrana bastırılıyor
    cout << "sinifin not ortalamasi :" << ogrencibilgi.ogrencinotortalamalaritoplami / ogrencibilgi.ogrencisayisi << endl;
    cout << "en buyuk ortalama not degeri :" << ogrencibilgi.ortalamalarınbuyuknot << endl << "en kucuk ortalama not degeri :" << ogrencibilgi.ortalamalarınkucuknot << endl << "en buyuk not degeri :" << ogrencibilgi.buyuknot << endl << "en kucuk not degeri :" << ogrencibilgi.kucuknot << endl;
    cout << "ortalamaya gore AA notu sayisi :" << ogrencibilgi.ortalamalarınAAsayisi << " ortalamaya gore AA notu yuzdesi :" << 100 * (float)ogrencibilgi.ortalamalarınAAsayisi / ogrencibilgi.ogrencisayisi << endl << "ortalamaya gore BA notu sayisi :" << ogrencibilgi.ortalamalarınBAsayisi << " ortalamaya gore BA notu yuzdesi :" << 100 * (float)ogrencibilgi.ortalamalarınBAsayisi / ogrencibilgi.ogrencisayisi << endl << "ortalamaya gore BB notu sayisi :" << ogrencibilgi.ortalamalarınBBsayisi << " ortalamaya gore BB notu yuzdesi :" << 100 * (float)ogrencibilgi.ortalamalarınBBsayisi / ogrencibilgi.ogrencisayisi << endl << "ortalamaya gore CB notu sayisi :" << ogrencibilgi.ortalamalarınCBsayisi << " ortalamaya gore CB notu yuzdesi :" << 100 * (float)ogrencibilgi.ortalamalarınCBsayisi / ogrencibilgi.ogrencisayisi << endl << "ortalamaya gore CC notu sayisi :" << ogrencibilgi.ortalamalarınCCsayisi << " ortalamaya gore CC notu yuzdesi :" << 100 * (float)ogrencibilgi.ortalamalarınCCsayisi / ogrencibilgi.ogrencisayisi << endl << "ortalamaya gore DC notu sayisi :" << ogrencibilgi.ortalamalarınDCsayisi << " ortalamaya gore DC notu yuzdesi :" << 100 * (float)ogrencibilgi.ortalamalarınDCsayisi / ogrencibilgi.ogrencisayisi << endl << "ortalamaya gore DD notu sayisi :" << ogrencibilgi.ortalamalarınDDsayisi << " ortalamaya gore DD notu yuzdesi :" << 100 * (float)ogrencibilgi.ortalamalarınDDsayisi / ogrencibilgi.ogrencisayisi << endl << "ortalamaya gore FD notu sayisi :" << ogrencibilgi.ortalamalarınFDsayisi << " ortalamaya gore FD notu yuzdesi :" << 100 * (float)ogrencibilgi.ortalamalarınFDsayisi / ogrencibilgi.ogrencisayisi << endl << "ortalamaya gore FF notu sayisi :" << ogrencibilgi.ortalamalarınFFsayisi << " ortalamaya gore FF notu yuzdesi :" << 100 * (float)ogrencibilgi.ortalamalarınFFsayisi / ogrencibilgi.ogrencisayisi << endl;
    cout << "AA notu sayisi :" << ogrencibilgi.AAsayisi << " AA notu yuzdesi :" << 100 * (float)ogrencibilgi.AAsayisi / ogrencibilgi.sinavsayisi << endl << "BA notu sayisi :" << ogrencibilgi.BAsayisi << " BA notu yuzdesi :" << 100 * (float)ogrencibilgi.BAsayisi / ogrencibilgi.sinavsayisi << endl << "BB notu sayisi :" << ogrencibilgi.BBsayisi << " BB notu yuzdesi :" << 100 * (float)ogrencibilgi.BBsayisi / ogrencibilgi.sinavsayisi << endl << "CB notu sayisi :" << ogrencibilgi.sinavsayisi << " CB notu yuzdesi :" << 100 * (float)ogrencibilgi.CBsayisi / ogrencibilgi.sinavsayisi << endl << "CC notu sayisi :" << ogrencibilgi.CCsayisi << " CC notu yuzdesi :" << 100 * (float)ogrencibilgi.CCsayisi / ogrencibilgi.sinavsayisi << endl << "DC notu sayisi :" << ogrencibilgi.DCsayisi << " DC notu yuzdesi :" << 100 * (float)ogrencibilgi.DCsayisi / ogrencibilgi.sinavsayisi << endl << "DD notu sayisi :" << ogrencibilgi.DDsayisi << " DD notu yuzdesi :" << 100 * (float)ogrencibilgi.DDsayisi / ogrencibilgi.sinavsayisi << endl << "FD notu sayisi :" << ogrencibilgi.FDsayisi << " FD notu yuzdesi :" << 100 * (float)ogrencibilgi.FDsayisi / ogrencibilgi.sinavsayisi << endl << "FF notu sayisi :" << ogrencibilgi.FFsayisi << " FF notu yuzdesi :" << 100 * (float)ogrencibilgi.FFsayisi / ogrencibilgi.sinavsayisi << endl;

    //standar sapma değeri hesaplanıp ekrana bastırılıyor
    // gecicitoplam standart sapma formülündeki[ (eleman1-ortalama)^2 + (eleman2-ortalama)^2 + (eleman3-ortalama)^2 .........(elemanx-ortalama)^2 ] toplama karşılık geliyor
    float gecicitoplam = 0;
    for (int sayac = 1;sayac <= ogrencibilgi.ogrencisayisi;sayac++)
    {
        gecicitoplam += pow(ogrencinotortalamalari[sayac] - ogrencibilgi.ogrencinotortalamalaritoplami / (float)ogrencibilgi.ogrencisayisi, 2);
    }
    ogrencibilgi.standartsapma = sqrt(gecicitoplam / (ogrencibilgi.ogrencisayisi - 1));
    cout << "standart sapma degeri :" << ogrencibilgi.standartsapma;
    //bellekteki ayırdığımız yerleri temizliyoruz
    free(vize);
    free(odev1);
    free(odev2);
    free(kisasinav1);
    free(kisasinav2);
    free(yilicisinav);
    free(finalnot);
    free(ogrencinotortalamalari);
    free(rastgelesayiisimicin);
    free(rastgelesayisoyisimicin);
    
}


