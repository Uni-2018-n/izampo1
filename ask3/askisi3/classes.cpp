#include "classes.hpp"

//#define DEBUG

int Object::temp_id=0;

///////////////////////////////////////Object
Object::Object(){
	id= temp_id++;
	#ifndef DEBUG
	cout << "Object just Created!" << endl;
	#endif
}

Object::~Object(){
	#ifndef DEBUG
	cout << "Object just destroyed!" << endl;
	#endif
}

bool Object::equal(const Object& sec)const{
	if(id == sec.get_id()){
		return true;
	}else{
		return false;
	}
}

bool Object::identical(const Object& sec)const{
	if(this == &sec){
		return true;
	}else{
		return false;
	}
}

String Object::toString()const{
	String temp("Object, id= " + to_string(id) + ", ");
	return temp;
}

int Object::get_temp_id()const{
	return temp_id;
}

int Object::get_id()const{
	return id;
}

///////////////////////////////////////String
String::String(const string temp):
txt(temp){
	#ifndef DEBUG
	cout << "String just Created! with id: " << get_id() << endl;
	#endif
}

String::~String(){
	#ifndef DEBUG
	cout << "String just destroyed!" << endl;
	#endif
}

int String::length()const{
	return txt.length();
}

void String::clear(){
	txt.clear();
}

void String::concat(const String sec){
	txt = txt+ sec.txt;
}

void String::concat(const string sec){//used for convenience
	txt=txt + sec;
}

char String::at(int pos)const{
	return txt[pos];
}

void String::updateAt(const int pos, const char rep){
	txt[pos]=rep;
}

void String::print()const{
	cout << txt << endl;
}

String* String::clone()const{
	String* temp= new String(txt);
	temp->temp_id=get_temp_id();
	temp->id=get_id();
	return temp;
}

String String::toString()const{
	String temp(Object::toString().get_txt() + " String, txt=" + txt);
	return temp;
}

string String::get_txt()const{
	return txt;
}

bool String::equal(const String& sec)const{
	if(Object::equal(sec)){
		if(txt == sec.txt){
			return true;
		}
	}
	return false;
}

///////////////////////////////////////Employee
Employee::Employee(){
	#ifndef DEBUG
	cout << "Employee just created ";
	cout << "Employee ID: " << get_id() << endl;
	#endif
}

Employee::~Employee(){
	delete name;
	#ifndef DEBUG
	cout << "Employee to be destroyed" << endl;
	#endif
}

bool Employee::equal(const Employee& sec)const{
	if(Object::equal(sec)){//check the Object::equal first
		if(name->get_txt() ==sec.name->get_txt()){//and then check the rest
			return true;
		}else{
			return false;
		}
	}else{
		return false;
	}
}

String Employee::toString()const{
	String temp(Object::toString().get_txt() + "Employee, " + name->get_txt() + " , ");
	return temp;
}

String* Employee::get_name()const{
	return name;
}

///////////////////////////////////////SecurityEmployee
SecurityEmployee::SecurityEmployee(const String& nam){
	name= nam.clone();//clone the nam to name to use for the Employee
	#ifndef DEBUG
	cout << "SecurityEmployee just created " << endl;
	#endif
}

SecurityEmployee::~SecurityEmployee(){
	#ifndef DEBUG
	cout << "SecurityEmployee to be destroyed" << endl;
	#endif
}

void SecurityEmployee::workOn(CargoBay& work_place){
	cout << "I SecurityEmployee, started working into a Cargo Bay" << endl;
	work_place.process(*this);//workOn calls process to change the bool variables of the PlaneComponent
}
void SecurityEmployee:: workOn(EquipmentCompartment& work_place){
	cout << "I SecurityEmployee, started working into a Equipment Compartment" << endl;
	work_place.process(*this);
}
void SecurityEmployee::workOn(PassengerCompartment& work_place){
	cout << "I SecurityEmployee, started working into a Passenger Compartment" << endl;
	work_place.process(*this);
}

void SecurityEmployee::report(const CargoBay& work_place)const{
	cout << "SecurityEmployee keep working on CargoBay" << endl;
}
void SecurityEmployee::report(const EquipmentCompartment& work_place)const{
	cout << "SecurityEmployee keep working on EquipmentCompartment" << endl;
}

void SecurityEmployee::report(const PassengerCompartment& work_place)const{
	cout << "SecurityEmployee keep working on PassengerCompartment" << endl;
}

bool SecurityEmployee::equal(const SecurityEmployee& sec)const{
	if(Employee::equal(sec)){
		return true;
	}else{
		return false;
	}
}

SecurityEmployee* SecurityEmployee::clone()const{
	SecurityEmployee* temp= new SecurityEmployee(*name);
	temp->id= get_id();
	return temp;
}

String SecurityEmployee::toString()const{
	String temp(Employee::toString().get_txt() + "SecurityEmployee");
	return temp;
}

///////////////////////////////////////MaintenanceEmployee
MaintenanceEmployee::MaintenanceEmployee(const String& nam){
	name= nam.clone();
	#ifndef DEBUG
	cout << "MaintenanceEmployee just created " << endl;
	#endif
}

MaintenanceEmployee::~MaintenanceEmployee(){
	#ifndef DEBUG
	cout << "MaintenanceEmployee to be destroyed" << endl;
	#endif
}

void MaintenanceEmployee:: workOn(CargoBay& work_place){
	cout << "I MaintenanceEmployee, started working into a Cargo Bay" << endl;
	work_place.process(*this);
}
void MaintenanceEmployee::workOn(EquipmentCompartment& work_place){
	cout << "I MaintenanceEmployee, started working into a Equipment Compartment" << endl;
	work_place.process(*this);
}

void MaintenanceEmployee::report(const CargoBay& work_place)const{
	cout << "MaintenanceEmployee keep working on CargoBay" << endl;
}
void MaintenanceEmployee::report(const EquipmentCompartment& work_place)const{
	cout << "MaintenanceEmployee keep working on EquipmentCompartment" << endl;
}

bool MaintenanceEmployee::equal(const MaintenanceEmployee& sec)const{
	if(Employee::equal(sec)){
		return true;
	}else{
		return false;
	}
}

MaintenanceEmployee* MaintenanceEmployee::clone()const{
	MaintenanceEmployee* temp = new MaintenanceEmployee(*name);
	temp->id=get_id();
	return temp;
}

String MaintenanceEmployee::toString()const{
	String temp(Employee::toString().get_txt() + "MaintenanceEmployee");
	return temp;
}

///////////////////////////////////////CleaningEmployee
CleaningEmployee::CleaningEmployee(const String nam){
	name= nam.clone();
	#ifndef DEBUG
	cout << "CleaningEmployee just created " << endl;
	#endif
}

CleaningEmployee::~CleaningEmployee(){
	#ifndef DEBUG
	cout << "CleaningEmployee to be destroyed" << endl;
	#endif
}

void CleaningEmployee:: workOn(CargoBay& work_place){
	cout << "I CleaningEmployee, started working into a Cargo Bay" << endl;
	work_place.process(*this);
}
void CleaningEmployee::workOn(PassengerCompartment& work_place){
	cout << "I CleaningEmployee, started working into a Passenger Compartment" << endl;
	work_place.process(*this);
}

void CleaningEmployee::workOn(PrivateCompartment& work_place){
	cout << "I CleaningEmployee, started working into a Private Compartment" << endl;
	work_place.process(*this);
}

void CleaningEmployee::report(const CargoBay& work_place)const{
	cout << "CleaningEmployee keep working on CargoBay" << endl;
}

void CleaningEmployee::report(const PassengerCompartment& work_place)const{
	cout << "CleaningEmployee keep working on Passenger Compartment" << endl;
}

void CleaningEmployee::report(const PrivateCompartment& work_place)const{
	cout << "CleaningEmployee keep working on Private compartment" << endl;
}

String CleaningEmployee::toString()const{
	String temp(Employee::toString().get_txt() + "CleaningEmployee");
	return temp;
}

bool CleaningEmployee::equal(const CleaningEmployee& sec)const{
	if(Employee::equal(sec)){
		return true;
	}else{
		return false;
	}
}

CleaningEmployee* CleaningEmployee::clone()const{
	CleaningEmployee* temp= new CleaningEmployee(*name);
	temp->id=get_id();
	return temp;
}

///////////////////////////////////////PlaneComponent
PlaneComponent::PlaneComponent(){
	#ifndef DEBUG
	cout << "PlaneComponent just created ";
	cout << "PlaneComponent ID: " << get_id() << endl;
	#endif
}

PlaneComponent::~PlaneComponent(){
	#ifndef DEBUG
	cout << "PlaneComponent to be destroyed" << endl;
	#endif
}

bool PlaneComponent::equal(const PlaneComponent& sec)const{
	if(Object::equal(sec)){
		return true;
	}else{
		return false;
	}
}

String PlaneComponent::toString()const{
	String temp(Object::toString().get_txt() + "PlaneComponent, ");
	return temp;
}

///////////////////////////////////////PassengerCompartment
PassengerCompartment::PassengerCompartment(){//constructor to create "parent" PassengerCompartment
	SecWorker= false;
	CleanWorker = false;
	#ifndef DEBUG
	cout << "PassengerCompartment just created " << endl;
	#endif
	if((rand() % 3) == 0){//and 1/4 chance to create a Sub PassengerCompartment
		#ifndef DEBUG
			cout << "Sub PassengerCompartment about to be created:" << endl;
		#endif
		Sub_PassCompartment = new PassengerCompartment();
	}else{
		Sub_PassCompartment = NULL;
	}
}

PassengerCompartment::PassengerCompartment(bool subs){//constructor to create only "parent" PassengerCompartment
		SecWorker= false;
		CleanWorker = false;
		#ifndef DEBUG
		cout << "PassengerCompartment just created " << endl;
		#endif
		Sub_PassCompartment = NULL;
}

PassengerCompartment::~PassengerCompartment(){
	#ifndef DEBUG
	cout << "PassengerCompartment to be destroyed" << endl;
	#endif
	delete Sub_PassCompartment;
}

void PassengerCompartment::process(SecurityEmployee& worker){
	if(Sub_PassCompartment != NULL){//set the worker to work on the Sub_PassCompartment if it exists
		cout << "{Sub PassengerCompartment: ";
		worker.workOn(*Sub_PassCompartment);//work
		worker.report(*Sub_PassCompartment);//and report
		cout << "}" << endl;
	}
	SecWorker= true;//then set the variables for the "parent" PassengerCompartment
}

void PassengerCompartment::process(CleaningEmployee& worker){
	if(Sub_PassCompartment != NULL){
		cout << "{Sub PassengerCompartment: ";
		worker.workOn(*Sub_PassCompartment);
		worker.report(*Sub_PassCompartment);
		cout << "}" << endl;
	}
	CleanWorker=true;
}

bool PassengerCompartment::equal(const PassengerCompartment& sec)const{
	if(PlaneComponent::equal(sec)){//first check the hyper class
		if(SecWorker == sec.SecWorker && CleanWorker == sec.CleanWorker){
			if(Sub_PassCompartment != NULL && sec.Sub_PassCompartment != NULL){//then check the Sub compartments
				return Sub_PassCompartment->equal(*(sec.Sub_PassCompartment));
			}else{
				return true;
			}
		}
	}
	return false;
}

PassengerCompartment* PassengerCompartment::clone()const{
	PassengerCompartment* temp= new PassengerCompartment(true);
	temp->SecWorker= SecWorker;//clone the variable data
	temp->CleanWorker= CleanWorker;
	if(Sub_PassCompartment != NULL){//check and if need clone the sub compartments
		temp->Sub_PassCompartment= Sub_PassCompartment->clone();
	}
	temp->id= get_id();//copy the id of the Object hyperclass
	return temp;
}

bool PassengerCompartment::ready_check()const{
	if(SecWorker && CleanWorker){//check if the workers have changed the variables
		cout << "PassengerCompartment OK!" << endl;
		toString().print();
		if(Sub_PassCompartment != NULL){//and then ready_check the sub compartments if they exist
			cout << "Sub: ";
			if(!(Sub_PassCompartment->ready_check())){
				return false;
			}
		}
		return true;
	}else{
		return false;
	}
}

String PassengerCompartment::toString()const{
	String temp(PlaneComponent::toString().get_txt() + "PassengerCompartment, ");
	if(SecWorker){//check if the workers have worked and add it in the description of the compartment
		temp.concat("SecurityEmployee worked here, ");
	}else{
		temp.concat("Need SecurityEmployee to work here, ");
	}
	if(CleanWorker){
		temp.concat("CleaningEmployee worked here, ");
	}else{
		temp.concat("Need CleaningEmployee to work here, ");
	}
	if(Sub_PassCompartment != NULL){//also add the description of the Sub compartments
		temp.concat("\n	{Sub_PassCompartment, " + Sub_PassCompartment->toString().get_txt() + "}");
	}else{
		temp.concat("No Sub_PassCompartment.");
	}
	return temp;
}

PassengerCompartment* PassengerCompartment::get_SubPass()const{
	return Sub_PassCompartment;
}

bool PassengerCompartment::get_SecWork()const{
	return SecWorker;
}

bool PassengerCompartment::get_CleanWork()const{
	return CleanWorker;
}

///////////////////////////////////////PrivateCompartment
PrivateCompartment::PrivateCompartment(){
	SecWorker= false;
	CleanWorker= false;
	#ifndef DEBUG
	cout << "PrivateCompartment just created " << endl;
	#endif
}

PrivateCompartment::~PrivateCompartment(){
	#ifndef DEBUG
	cout << "PrivateCompartment to be destroyed" << endl;
	#endif
}

void PrivateCompartment::process(SecurityEmployee& worker){
	SecWorker = true;
}

void PrivateCompartment::process(CleaningEmployee& worker){
	CleanWorker = true;
}

bool PrivateCompartment::equal(const PrivateCompartment& sec)const{
	if(PlaneComponent::equal(sec)){
		if(SecWorker == sec.SecWorker && CleanWorker == sec.CleanWorker){
			return true;
		}
	}
	return false;
}

bool PrivateCompartment::ready_check()const{
	if(SecWorker && CleanWorker){
		cout << "PrivateCompartment OK!" << endl;
		return true;
	}else{
		return false;
	}
}

String PrivateCompartment::toString()const{
	String temp(PlaneComponent::toString().get_txt() + "PrivateCompartment, ");
	if(SecWorker){
		temp.concat("SecurityEmployee worked here, ");
	}else{
		temp.concat("Need SecurityEmployee to work here, ");
	}
	if(CleanWorker){
		temp.concat("CleaningEmployee worked here. ");
	}else{
		temp.concat("Need CleaningEmployee to work here, ");
	}
	return temp;
}

bool PrivateCompartment::get_SecWork()const{
	return SecWorker;
}

bool PrivateCompartment::get_CleanWork()const{
	return CleanWorker;
}

///////////////////////////////////////EquipmentCompartment
EquipmentCompartment::EquipmentCompartment(){
	SecWorker= false;
	MaintWorker= false;
	#ifndef DEBUG
	cout << "EquipmentCompartment just created " << endl;
	#endif
}

EquipmentCompartment::~EquipmentCompartment(){
	#ifndef DEBUG
	cout << "EquipmentCompartment to be destroyed" << endl;
	#endif
}

void EquipmentCompartment::process(SecurityEmployee& worker){
	PrivateCompartment::process(worker);//work into the PrivateCompartment
	SecWorker= true;
}

void 	EquipmentCompartment::process(MaintenanceEmployee& worker){
	MaintWorker = true;
}

void EquipmentCompartment::process(CleaningEmployee& worker){//since CleanWorkers dont need to work on EquipmentCompartments but they need to work
	PrivateCompartment::process(worker);//into a PrivateCompartment
}

bool EquipmentCompartment::equal(const EquipmentCompartment& sec)const{
	if(PrivateCompartment::equal(sec)){//first check the hyperclass and then the current class
		if(SecWorker == sec.SecWorker && MaintWorker == sec.MaintWorker){
			return true;
		}
	}
	return false;
}

EquipmentCompartment* EquipmentCompartment::clone()const{
	EquipmentCompartment* temp = new EquipmentCompartment;
	temp->SecWorker = SecWorker;
	temp->MaintWorker = MaintWorker;
	temp->PrivateCompartment::SecWorker = PrivateCompartment::SecWorker;//copy the variables for the Hyper class
	temp->PrivateCompartment::CleanWorker = PrivateCompartment::CleanWorker;
	temp->id= get_id();
	return temp;
}

bool EquipmentCompartment::ready_check()const{
	if(PrivateCompartment::ready_check()){
		if(SecWorker && MaintWorker){
			cout << "EquipmentCompartment OK!" << endl;
			toString().print();
			return true;
		}else{
			return false;
		}
	}else{
		return false;
	}
}

String EquipmentCompartment::toString()const{
	String temp(PrivateCompartment::toString().get_txt() + "EquipmentCompartment, ");
	if(SecWorker){
		temp.concat("SecurityEmployee worked here, ");
	}else{
		temp.concat("Need SecurityEmployee to work here, ");
	}
	if(MaintWorker){
		temp.concat("MaintenanceEmployee worked here. ");
	}else{
		temp.concat("Need MaintenanceEmployee to work here. ");
	}
	return temp;
}

bool EquipmentCompartment::get_SecWork()const{
	return SecWorker;
}

bool EquipmentCompartment::get_MaintWork()const{
	return MaintWorker;
}

///////////////////////////////////////CargoBay
CargoBay::CargoBay(){
	SecWorker= false;
	CleanWorker= false;
	MaintWorker= false;
	#ifndef DEBUG
	cout << "CargoBay just created " << endl;
	cout << "Equipment_space is about to be created:" << endl;
	#endif
	equipment_space= new EquipmentCompartment();
}

CargoBay::~CargoBay(){
	#ifndef DEBUG
	cout << "CargoBay to be destroyed" << endl;
	#endif
	delete equipment_space;
}

void CargoBay::process(SecurityEmployee& worker){
	PrivateCompartment::process(worker);//work on PrivateCompartment
	cout << "Equipment_space of CargoBay: ";//then the Sub Equipment_space
	worker.workOn(*equipment_space);
	worker.report(*equipment_space);
	SecWorker = true;
}

void CargoBay::process(CleaningEmployee& worker){
	PrivateCompartment::process(worker);//Work on PrivateCompartment
	equipment_space->process(worker);//then work on PrivateCompartment of Sub Equipment_space
	CleanWorker = true;
}

void CargoBay::process(MaintenanceEmployee& worker){
	cout << "Equipment_space of CargoBay: ";
	worker.workOn(*equipment_space);
	worker.report(*equipment_space);
	MaintWorker = true;
}

bool CargoBay::equal(const CargoBay& sec)const{
	if(PrivateCompartment::equal(sec)){
		if(SecWorker == sec.SecWorker && CleanWorker == sec.CleanWorker && MaintWorker == sec.MaintWorker){
			if(equipment_space->equal(*(sec.equipment_space))){
				return true;
			}
		}
	}
	return false;
}

String CargoBay::toString()const{
	String temp(PrivateCompartment::toString().get_txt() + "CargoBay, ");

	if(SecWorker){
		temp.concat("SecurityEmployee worked here, ");
	}else{
		temp.concat("Need SecurityEmployee to work here, ");
	}
	if(CleanWorker){
		temp.concat("CleaningEmployee worked here, ");
	}else{
		temp.concat("Need CleaningEmployee to work here, ");
	}
	if(MaintWorker){
		temp.concat("MaintenanceEmployee worked here. ");
	}else{
		temp.concat("Need MaintenanceEmployee to work here. ");
	}
	temp.concat("\n	{CargoBay's Equipment_space, " + equipment_space->toString().get_txt() + "}");
	return temp;
}

bool CargoBay::ready_check()const{
	if(PrivateCompartment::ready_check()){
		if(equipment_space->ready_check()){
			if(SecWorker && CleanWorker && MaintWorker){
				cout << "CargoBay OK!" << endl;
				toString().print();
				return true;
			}else{
				return false;
			}
		}else{
			return false;
		}
	}else {
		return false;
	}
}

CargoBay* CargoBay::clone()const{
	CargoBay* temp= new CargoBay;
	delete temp->equipment_space;
	temp->SecWorker = SecWorker;
	temp->CleanWorker = CleanWorker;
	temp->MaintWorker = MaintWorker;
	temp->equipment_space = equipment_space->clone();
	temp->PrivateCompartment::SecWorker = PrivateCompartment::SecWorker;
	temp->PrivateCompartment::CleanWorker = PrivateCompartment::CleanWorker;
	temp->id= get_id();
	return temp;
}

EquipmentCompartment* CargoBay::get_equip_space()const{
	return equipment_space;
}

bool CargoBay::get_SecWork()const{
	return SecWorker;
}

bool CargoBay::get_CleanWork()const{
	return CleanWorker;
}

bool CargoBay::get_MaintWork()const{
	return MaintWorker;
}

///////////////////////////////////////Plane
Plane::Plane(const String& titl, const int ma_pl)://normal constractor
max_pl(ma_pl){
	#ifndef DEBUG
	cout << "Plane just created ";
	cout << "Plane with ID: " << get_id() << endl;
	#endif
	title= new String(titl);
	cargo = new CargoBay();
	#ifndef DEBUG
	cout << "CARGOBAY DONE" << endl;
	#endif
	e1= new EquipmentCompartment();
	#ifndef DEBUG
	cout << "E1 DONE" << endl;
	#endif
	e2= new EquipmentCompartment();
	#ifndef DEBUG
	cout << "E2 DONE " << endl;
	#endif
	e3= new EquipmentCompartment();
	#ifndef DEBUG
	cout << "E3 DONE" << endl;
	#endif

	float temp = max_pl/75.0;
	if(temp == (int)temp){
		size_PassComp = (int)temp;
	}else{
		size_PassComp = ((int)temp)+ 1;
	}
	pl_PassComp= new PassengerCompartment*[size_PassComp];
	for(int i=0;i<size_PassComp;i++){
		pl_PassComp[i]= new PassengerCompartment;
		#ifndef DEBUG
		cout << "PASS COMPARTMENT DONE" << endl << endl << endl;
		#endif
	}
}

Plane::Plane(){//constructor used on clone
	#ifndef DEBUG
	cout << "Plane just created ";
	#endif
}

Plane::~Plane(){
	delete title;
	delete cargo;
	delete e1;
	delete e2;
	delete e3;
	for(int i=0;i<size_PassComp;i++){
		delete pl_PassComp[i];
	}
	delete[] pl_PassComp;

	#ifndef DEBUG
	cout << "Plane to be destroyed" << endl;
	#endif
}

void Plane::process(SecurityEmployee& worker){
	if(!cargo->ready_check()){//check every sub compartment if its ready or not
		worker.workOn(*cargo);//if not worker must work here
		worker.report(*cargo);//and report were worked
	}
	if(!e1->ready_check()){//since one worker can work on all the PlaneComponents
		worker.workOn(*e1); //continue with the next component(this was explained in the forum)
		worker.report(*e1);
	}
	if(!e2->ready_check()){
		worker.workOn(*e2);
		worker.report(*e2);
	}
	if(!e3->ready_check()){
		worker.workOn(*e3);
		worker.report(*e3);
	}
	for(int i=0;i<size_PassComp;i++){
		if(!pl_PassComp[i]->ready_check()){
			worker.workOn(*pl_PassComp[i]);
			worker.report(*pl_PassComp[i]);
		}
	}
}

void Plane::process(MaintenanceEmployee& worker){
	if(!cargo->ready_check()){
		worker.workOn(*cargo);
		worker.report(*cargo);
	}
	if(!e1->ready_check()){
		worker.workOn(*e1);
		worker.report(*e1);
	}
	if(!e2->ready_check()){
		worker.workOn(*e2);
		worker.report(*e2);
	}
	if(!e3->ready_check()){
		worker.workOn(*e3);
		worker.report(*e3);
	}
}

void Plane::process(CleaningEmployee& worker){
	if(!cargo->ready_check()){
		worker.workOn(*cargo);
		worker.report(*cargo);
	}
	if(!e1->ready_check()){
		worker.workOn(*e1);
		worker.report(*e1);
	}
	if(!e2->ready_check()){
		worker.workOn(*e2);
		worker.report(*e2);
	}
	if(!e3->ready_check()){
		worker.workOn(*e3);
		worker.report(*e3);
	}
	for(int i=0;i<size_PassComp;i++){
		if(!pl_PassComp[i]->ready_check()){
			worker.workOn(*pl_PassComp[i]);
			worker.report(*pl_PassComp[i]);
		}
	}
}

bool Plane::equal(const Plane& sec)const{
	if(title->get_txt() == sec.title->get_txt() && max_pl == sec.max_pl){
		if(cargo->equal(*(sec.cargo))){
			if(e1->equal(*(sec.e1)) && e2->equal(*(sec.e2)) && e3->equal(*(sec.e3))){
				for(int i=0;i<size_PassComp;i++){
					if(!(pl_PassComp[i]->equal(*(sec.pl_PassComp[i])))){
						return false;
					}
				}
				return Object::equal(sec);
			}
		}
	}
	return false;
}

bool Plane::ready_check()const{
	if(!cargo->ready_check()){
		return false;
	}
	if(!e1->ready_check()){
		return false;
	}
	if(!e2->ready_check()){
		return false;
	}
	if(!e3->ready_check()){
			return false;
	}
	for(int i=0;i<size_PassComp;i++){
		if(!pl_PassComp[i]->ready_check()){
			return false;
		}
	}
	return true;
}

String Plane::toString()const{
	String temp(Object::toString().get_txt() +
	"Plane, title= " + title->get_txt() + ", max_pl= " + to_string(max_pl) + ", " +
	"Parts: \n" +
	cargo->toString().get_txt() + "\n" + e1->toString().get_txt() + "\n" + e2->toString().get_txt() + "\n" + e3->toString().get_txt());
 	for(int i=0;i<size_PassComp;i++){
		temp.concat("\n" + pl_PassComp[i]->toString().get_txt());
	}
	return temp;
}

Plane* Plane::clone()const{
	Plane* temp= new Plane();//create a plane with no sub components
	temp->title = title->clone();//clone the components
	temp->max_pl = max_pl;
	temp->size_PassComp = size_PassComp;
	temp->cargo=cargo->clone();
	temp->e1=e1->clone();
	temp->e2=e2->clone();
	temp->e3=e3->clone();
	temp->pl_PassComp = new PassengerCompartment*[temp->size_PassComp];
	for(int i=0;i<temp->size_PassComp;i++){
		temp->pl_PassComp[i]= pl_PassComp[i]->clone();
	}
	temp->id= get_id();
	return temp;
}

String* Plane::get_title()const{
	return title;
}

int Plane::get_max_pl()const{
	return max_pl;
}

int Plane::get_size_passcomp()const{
	return size_PassComp;
}

CargoBay* Plane::get_cargo()const{
	return cargo;
}

EquipmentCompartment* Plane::get_e1()const{
	return e1;
}

EquipmentCompartment* Plane::get_e2()const{
	return e2;
}

EquipmentCompartment* Plane::get_e3()const{
	return e3;
}

PassengerCompartment** Plane::get_pl_passcomp()const{
	return pl_PassComp;
}

//Clone encrypt and print
void clone_encrypt_and_print(const Object& sec){
	Object* temp=sec.clone();
	cout << "Equal: ";
	if(temp->equal(sec)){
		cout << "TRUE" << endl;
	}else{
		cout << "FALSE" << endl;
	}
	String tempSTR= temp->toString();
	String secSTR= sec.toString();

	int rand_how_many = rand() % tempSTR.length();//find how many of the characters will get replaced
	int change;
	int from;
	for(int i=0;i<rand_how_many;i++){
		change= rand()% (tempSTR.length() - 1);//can change every character except the '\0'
		from = rand()% (tempSTR.length() - 1);
		tempSTR.updateAt(change, tempSTR.at(from));//change it
	}
	cout << endl << "tempSTR: ";
	tempSTR.print();
	cout << endl << "secSTR: ";
	secSTR.print();

	tempSTR.concat(secSTR);
	cout << endl <<"length after concat: " << tempSTR.length() << endl;
	cout << "Midle ";
	if(tempSTR.length() % 2 != 0){
		cout << "characters: ";
		cout << tempSTR.at((int)tempSTR.length()/2) << ", " << tempSTR.at(((int)tempSTR.length()/2) + 1) << endl;
	}else{
		cout << "character: ";
		cout << tempSTR.at(tempSTR.length()/2) << endl;
	}
	tempSTR.clear();
	cout << "length of tempSTR after clear: " << tempSTR.length() << endl;
	delete temp;
}
