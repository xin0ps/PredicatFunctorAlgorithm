#include <iostream>
#include <list>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

class DateTime
{
public:
    
    string year;
    string month;
    string day;
    DateTime() {
        year = "01";
        month = "01";
        month = "1900";
    }
    DateTime(const string Day,const string Month,const string Year) {
        year = Year;
        month = Month;
        day = Day;
    }

    string getDate() {
        string date = day + "/" + month + "/" + year;
        return date;
   }
};

class Debtor {
private:
    string FullName;
    DateTime BirthDay;
    string Phone;
    string Email;
    string Address;
    int Debt;
public:
    Debtor() = default;
    Debtor(const string fullname,  DateTime birthDay, const string phone, const string email, const string address, int debt) {
        FullName = fullname;
        BirthDay = birthDay;
        Phone = phone;
        Email = email;
        Address = address;
        Debt = debt;
    }
    string getName()const { return this->FullName; }
    DateTime getDate()const { return this->BirthDay; }
    string getPhone()const { return this->Phone; }
    string getEmail()const { return this->Email; }
    string getAdress()const { return this->Address; }
    int getDebt()const { return this->Debt; }

    void setName() { 
    
    }
    void setDate() { 
    
    }
    void setPhone() { 
    
    }
    void setEmail() { 
    
    }
    void setAdress() { 
    
    }
    void setDebt() {  
    
    }
 
};
void show(Debtor*& debtor)
{
    cout << "Fullname: " +  debtor->getName() + "\n" +"Birthday: " + debtor->getDate().getDate() + "\n"+"Phone: " + debtor->getPhone() + "\n"+"Email: " + debtor->getEmail() + "\n"+"Address: " + debtor->getAdress() + "\n"+"Debt: " + to_string(debtor->getDebt()) << endl;
    cout << "---------------------------------------------------------------------------------------" << endl;
}
bool removeByEmail(Debtor*& debtor)
{
    return !(debtor->getEmail().find("rhyta.com")!=string::npos || debtor->getEmail().find("dayrep.com")!= string::npos);
}
bool removeByAge(Debtor*& debtor)
{
    return !((2023 - stoi(debtor->getDate().year)) >= 26 && (2023 - stoi(debtor->getDate().year)) <= 36);
}
bool removeByDept(Debtor*& debtor)
{
    return !(debtor->getDebt()<5000);
}

bool removeByNameAndNumber(Debtor*& debtor)
{
    string name = debtor->getName();
    string phone = debtor->getPhone();

    

    return (name.size() < 18) || (count(name.begin(), name.end(), '7') < 2);
}
bool removeByWinter(Debtor*& debtor)
{
  int season= stoi(debtor->getDate().month);
  if (season == 12 || season == 1 || season == 2)
      return false;
  return true;
}



bool removeByWW2(Debtor*& debtor)
{
    int year = stoi(debtor->getDate().year);
    return year > 1945;
}
double getAverageDebt(const list<Debtor*>& debtorList) {
    double totalDebt = 0.0;
    for (Debtor* debtor : debtorList) {
        totalDebt += debtor->getDebt();
    }
    return totalDebt / debtorList.size();
}

void removeAndSortByDebt(list<Debtor*>& debtorList) {
    double averageDebt = getAverageDebt(debtorList);


    debtorList.remove_if([averageDebt](Debtor*& debtor) {
        return debtor->getDebt() > averageDebt;
        });

    debtorList.sort([](Debtor*& a, Debtor*& b) {
        return a->getName() < b->getName();
        });

    debtorList.sort([](Debtor*& a, Debtor*& b) {
        return a->getDebt() > b->getDebt();
        });
}

void listDebtorsbyPhone(const list<Debtor*>& debtorList) {
    for (Debtor* debtor : debtorList) {
        string phone = debtor->getPhone();
        if (phone.find('8') == string::npos) {
            cout << "Fullname: " << debtor->getName() << endl;
            cout << "Birthday: " << debtor->getDate().getDate() << endl;
            cout << "Debt: " << debtor->getDebt() << endl;
            cout << "---------------------------------------------------------------------------------------" << endl;
        }
    }
}

void removeByYear(list<Debtor*>& debtorList) {
    unordered_map<string, int> yearCountMap;

    for (Debtor* debtor : debtorList) {
        string year = debtor->getDate().year;
        yearCountMap[year]++;
    }

  
    string Year;
    int maxCount = 0;
    for (const auto& entry : yearCountMap) {
        if (entry.second > maxCount) {
            Year = entry.first;
            maxCount = entry.second;
        }
    }

   
    debtorList.remove_if([&Year](Debtor*& debtor) {
        return debtor->getDate().year == Year;
        });
}


void test(Debtor*& debtor)
{
    cout << 2023 - stoi(debtor->getDate().year);
}

int main() {
    list<Debtor*> debtorList;
    debtorList.push_back(new Debtor("Shirley T. Qualls", DateTime("20", "02", "1945"), "530-662-7732", "ShirleyTQualls@teleworm.us", "3565 Eagles Nest Drive Woodland, CA 95695", 2414));
    debtorList.push_back(new Debtor("Nancy J. Fergersonnn", DateTime("10", "06", "1932"), "219-987-8798", "NancyJFergerson@dayrep.com", "3584 Jadewood Drive Demotte, IN 46310", 1276));
    debtorList.push_back(new Debtor("Connie W. Lemire", DateTime("18", "12", "1990"), "828-321-3751", "ConnieWLemire@rhyta.com", "2432 Hannah Street Andrews, NC 28901", 1219));
    debtorList.push_back(new Debtor("Deanna J. Donofriooo", DateTime("16", "04", "1993"), "952-842-7576", "DeannaJDonofrio@rhyta.com", "1972 Orchard Street Bloomington, MN 55437", 515));
    debtorList.push_back(new Debtor("Robert T. Taylor", DateTime("17", "01", "1933"), "270-596-6442", "RobertTTaylor@armyspy.com", "2812 Rowes Lane Paducah, KY 42001", 7785));
    debtorList.push_back(new Debtor("Lionel A. Cook", DateTime("16", "04", "1999"), "201-627-5962", "LionelACook@jourrapide.com", "29 Goldleaf Lane Red Bank, NJ 07701", 2712));
    debtorList.push_back(new Debtor("Lionel A. Cook", DateTime("16", "04", "1999"), "012-345-6789", "LionelACook@jourrapide.com", "29 Goldleaf Lane Red Bank, NJ 07701", 2712));

    // 2 )rhyta.com ve dayrep.com domenlerinde emaili olan  cıxart

    debtorList.remove_if(removeByEmail);
    for_each(debtorList.begin(), debtorList.end(), show);

//    3) Yashi 26 - dan 36 - ya qeder olan borclulari cixartmag

     /* debtorList.remove_if(removeByAge);
    for_each(debtorList.begin(), debtorList.end(), show);*/
    

//    4) Borcu 5000 - den cox olmayan borclulari cixartmag

   /*    debtorList.remove_if(removeByDept);
    for_each(debtorList.begin(), debtorList.end(), show);*/


//    5) Butov adi 18 simvoldan cox olan ve telefon nomresinde 2 ve ya 2 - den cox 7 reqemi olan borclulari cixartmaq

  /*       debtorList.remove_if(removeByNameAndNumber);
    for_each(debtorList.begin(), debtorList.end(), show);*/


//    7) Qishda anadan olan borclulari cixardmaq


      /*   debtorList.remove_if(removeByWinter);
    for_each(debtorList.begin(), debtorList.end(), show);*/


//    8) Borcu, umumi borclarin orta borcunnan cox olan borclulari cixarmaq ve evvel familyaya gore sonra ise meblegin azalmagina gore sortirovka etmek
   
   /* removeAndSortByDebt(debtorList);
    for_each(debtorList.begin(), debtorList.end(), show);*/

//    9) Telefon nomresinde 8 olmayan borclularin yalniz familyasin, yashin ve umumi borcun meblegin cixarmaq

    //listDebtorsbyPhone(debtorList);

//    11)Adinda ve familyasinda hec olmasa 3 eyni herf olan borclularin siyahisin cixarmaq ve onlari elifba sirasina gore sortirovka elemek
//
//    13)borclulardan en coxu hansi ilde dogulubsa hemin ili cixartmaq

    //removeByYear(debtorList);
    //for_each(debtorList.begin(), debtorList.end(), show);

//    14)Borcu en boyuk olan 5 borclunun siyahisini cixartmaq
//
//    15)Butun borcu olanlarin borcunu cemleyib umumi borcu cixartmaq
//
//    16)2ci dunya muharibesin gormush borclularin siyahisi cixartmaq

         /* debtorList.remove_if(removeByWW2);
    for_each(debtorList.begin(), debtorList.end(), show);*/

//    18)Nomresinde tekrar reqemler olmayan borclularin ve onlarin borcunun meblegin cixartmaq
//
//    19)Tesevvur edek ki, butun borclari olanlar bugunden etibaren her ay 500 azn pul odeyecekler.Oz ad gunune kimi borcun oduyub qurtara bilenlerin siyahisin cixartmaq
//
//    20)Adindaki ve familyasindaki herflerden "smile" sozunu yaza bileceyimiz borclularin siyahisini cixartmaq
//
}
