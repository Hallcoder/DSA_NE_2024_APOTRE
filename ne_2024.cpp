#include<iostream>
#include<string>
using namespace std;

struct Patient{
	int patient_id;
	string name;
	string dob;
	string gender;
	Patient * next;
	
	Patient(int id, string n, string dateOfBirth, string gen){
		patient_id = id;
		name = n;
		dob = dateOfBirth;
		gender = gen;
		next = NULL;
      }
    Patient(){
    	next = NULL;
	}
	
	void display(){
		cout<<"Patient details :"<<patient_id<<","<<name<<","<<dob<<","<<gender<<endl;
	}
};

struct Doctor{
	Doctor * next;
	int doctor_id;
	string name;
	string specialization;
	
	Doctor(int id, string n, string spec){
		name = n;
		doctor_id = id;
		specialization = spec;
		next = NULL;
	}
	Doctor(){
		next = NULL;
	}
};

struct Appointment{
	Appointment * next;
	int appointment_id;
	int patient_id;
	int doctor_id;
	string appointment_date;
	
	Appointment(int appId, int pId, int dId, string appDate){
		appointment_id = appId;
		patient_id = pId;
		doctor_id = dId;
		appointment_date = appDate;
		next = NULL;
	}
	Appointment(){
		next = NULL;
	}
};

class PatientsLl{
private:
  Patient * head;	
public:
	PatientsLl(): head(nullptr){
	}
	void append(Patient * p){
		if(!head){
			head = p;
			return;
		}
		Patient * n = head;
		if(exists(p->patient_id)){
			cout<<"<<<<<<<<<<ERROR: ID provided is in use>>>>>>>>>>>\n"<<endl;
			return;
		}
		while(n->next){
			n = n->next;
		}
		n->next = p;
	}
	
	void print(){
		Patient * list = head;
		while(list){
			cout<<" *************** \n       PATIENTS \n ***************"<<endl;
			cout<<"Patient ID: "<<list->patient_id<<", "<<"Name: "<<list->name<<", "<<"DOB: "<<", "<<list->dob<<", "<<"Gender: "<<list->gender<<endl;
			list = list->next;
		}
		cout<<endl;
	}
	
	int exists(int id){
		Patient * list = head;
		while(list){
			if(list->patient_id == id){
				return 1;
			}
			list = list->next;
		}
		return 0;
	}
};
class DoctorsLl{
private:
  Doctor * head;
public:
      DoctorsLl():head(nullptr){
	  }
	void append(Doctor * p){
		if(!head){
			head = p;
			return;
		}
		Doctor * n = head;
		if(exists(p->doctor_id)){
			cout<<"<<<<<<<<<<ERROR: ID provided is in use>>>>>>>>>>>\n"<<endl;
			return;
		}
		while(n->next){
			n = n->next;
		}
		n->next = p;
	}
	
	void print(){
		Doctor * list = head;
		cout<<list->name<<endl;
		while(list){
			cout<<"*************** \n\t DOCTORS \n ***************"<<endl;
			cout<<"Doctor ID: "<<list->doctor_id<<", "<<"Name: "<<list->name<<", "<<"Specialization: "<<list->specialization<<endl;
			list = list->next;
		}
		cout<<endl;
	}
	
	int exists(int id){
		Doctor * list = head;
		while(list){
			if(list->doctor_id == id){
				return 1;
			}
			list = list->next;
		}
		return 0;
	}  
	
//  void append(D)	
};
class AppointmentsLl{
private:
	Appointment * head = NULL;
public:
      AppointmentsLl():head(nullptr){
	  }
	void append(Appointment * p, DoctorsLl * doctors, PatientsLl * patients){
		if(!doctors->exists(p->doctor_id) || !patients->exists(p->patient_id)){
			cout<<"<<<<<<<<<<ERROR: Patient or Doctor doesn't exist>>>>>>>>>>>\n"<<endl;
			return;
		}
		if(!head){
			head = p;
			return;
		}
		if(exists(p->appointment_id)){
		   cout<<"<<<<<<<<<<ERROR: ID provided is in use>>>>>>>>>>>\n"<<endl;
		   return;
		}
		Appointment * n = head;
	
		while(n->next){
			n = n->next;
		}
		n->next = p;
	}
	
	void print(){
		Appointment * list = head;
		while(list){
			cout<<"*************** \n\t APPOINTMENTS \n ***************"<<endl;
			cout<<"Appointment ID: "<<list->appointment_id<<", "<<"Patient ID: "<<list->patient_id<<", "<<"Doctor ID: "<<", "<<list->doctor_id<<", "<<"Date: "<<list->appointment_date<<endl;
			list = list->next;
		}
		cout<<endl;
	}
	
	int exists(int id){
		Appointment * list = head;
		while(list){
			if(list->appointment_id == id){
				return 1;
			}
			list = list->next;
		}
		return 0;
	}  
};
void success(){
	cout<<"********** CREATION SUCCESS! **********"<<endl;
}
void displayMenu(){
	cout<<"Menu: \n 1. Register a Patient \n 2. Register a doctor \n 3. Register an appointment \n 4. Display Patients \n 5. Display Doctors \n 6. Display appointments \n 7. Exit \n\n\n";
}
void check_number_input(int &num){
    while(true)
    {
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cerr<<"input must be a number: "<<endl;
            cin>>num;
        }
        if(!cin.fail())
            break;
    }
}
int main(){
	PatientsLl * patients = new PatientsLl();
    DoctorsLl * doctors = new DoctorsLl();
    AppointmentsLl appointments;
    while(true){
    int choice;
    displayMenu();
    cout<<"Enter your choice:";
    check_number_input(choice);
    	switch(choice){
    		case 1:
    		{	
			    cout<<"\t PATIENT REGISTRATION \n\t-------------------------- \n";	
    			Patient * p = new Patient();
    			cout<<"ID:";
    			cin>>p->patient_id;
    			cout<<"NAME:";
    			cin.ignore();
    			getline(cin,p->name);
    		    cout<<"DoB:";
    			cin>>p->dob;
    			cout<<"GENDER:";
    			cin>>p->gender;
    			patients->append(p);
    			success();
    			break;
    			//register a patient;
    		}
    		break;
    		case 2:
    			{
    			cout<<"\t Doctor REGISTRATION \n\t-------------------------- \n";	
    			Doctor* d = new Doctor();
    			cout<<"ID:";
    			cin>>d->doctor_id;
    			cout<<"NAME:";
    			cin.ignore();
    		    getline(cin,d->name);
    			cout<<"Specialization:";
    			cin>>d->specialization;
    			doctors->append(d);
    			success();
    			break;
    		}
    			//register a doctor
    		break;  		
    		case 3:
    			{
    			cout<<"\t APPOINTMENT REGISTRATION \n\t-------------------------- \n";	
    			Appointment * a  = new Appointment();
    			cout<<"ID:";
    			cin>>a->appointment_id;
    			cout<<"P_ID:";
    			cin>>a->patient_id;
    			cout<<"D_ID:";
    			cin>>a->doctor_id;
    			cout<<"DATE:";
    			cin>>a->appointment_date;
    			appointments.append(a,doctors,patients);
    			success();
    		}
    			//register an appointment
    		break;
    		
    		case 4:
    			patients->print();
    			//display patients
    		break;
    		
    		case 5:
    			doctors->print();
    			//display doctors
    		break;
    		
    		case 6:
    			appointments.print();
    			//display appointments
    		break;
    		
    		case 7:
    			exit(0);
    		break;
    		
    		default:
    			cout<<"Choose a valid option"<<endl;
		}
	}
	return 0;
}
