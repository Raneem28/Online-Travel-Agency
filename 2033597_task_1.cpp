#include "2023597_definitions_1.cpp"
int main()
{
    Person person_Record[5];
    Person P1;
    cout<<"Enter the name of the person: ";
    cin>>P1.p_name;
    cout<<"Enter the age of the person: ";
    cin>>P1.p_age;
    cout<<"Enter the address of the person (city first and then street): ";
    cin>>P1.p_address.city;
    cin>>P1.p_address.street;
    cout<<"Enter whether the person is a national or a foreigner(0 for Foreigner, or any number other than 0 for National): ";
    int nationality;
    cin >> nationality;

    if (nationality == 0) {
       cout<<"Enter passport number(without spaces and dash): "<<endl;
       cin>>P1.p_type.p_foreigner.f_passportNo;
       cout<<"Enter visitor number: "<<endl;
       cin>>P1.p_type.p_foreigner.f_visitorNo;
    } else {
        cout<<"Enter cnic number(without spaces and dash): "<<endl;
        cin>>P1.p_type.p_national.n_cnic;
        cout<<"Enter Family number: "<<endl;
        cin>>P1.p_type.p_national.n_familyNo;
    }
    cout<<"Enter the gender of the person(0 for male and any other number for female): "<<endl;
    int gen;
    cin >> gen;
    P1.p_gender = (gen == 0) ? Male : Female;
    cout<<"Enter the degrees of the person(not more than 3): ";
    for(int i=0;i<3;i++){
        cin>>P1.p_degrees[i];
    }
    cout<<endl;
    cout<<"--------------------------------------------------------------"<<endl;
    cout<<"The entered information is: "<<endl;
    coutpersonrecord(P1);
    cout<<endl;
    editpersonrecord(P1);

    cout << "----------------------------------------------------------------" << endl;
    cout << "The record after editing is: " << endl;
    coutpersonrecord(P1);
    cout<<"-------------------------THE END-----------------------------------";
}
