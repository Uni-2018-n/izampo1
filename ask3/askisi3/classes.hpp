#include <iostream>
using namespace std;

//forward declaration

class String;
class Employee;
class SecurityEmployee;
class MaintenanceEmployee;
class CleaningEmployee;

class PlaneComponent;
class PassengerCompartment;
class PrivateCompartment;
class EquipmentCompartment;
class CargoBay;

class Plane;

///////////////////////////////////////Object
class Object{
protected:
	static int temp_id;//temp_id is used as a static variable to get the id values for the objects
	int id;
public:
	Object();
	virtual ~Object();

	virtual bool equal(const Object& sec)const;
	bool identical(const Object& sec)const;

	virtual String toString()const;
	virtual Object* clone()const=0;
	int get_temp_id()const;
	int get_id()const;
};

///////////////////////////////////////String
class String:public Object{
	string txt;
public:
	String(const string temp);
	~String();

	int length()const;
	void clear();
	void concat(const String sec);
	void concat(const string sec);
	char at(int pos)const;
	void updateAt(const int pos, const char rep);
	void print()const;

	String* clone()const;
	String toString()const;
	string  get_txt()const;
	bool equal(const String& sec)const;
};

///////////////////////////////////////Employee
class Employee: public Object{
protected:
	String* name;
public:
	Employee();
	virtual ~Employee();

	virtual void workOn(CargoBay& work_place){};
	virtual void workOn(EquipmentCompartment& work_place){};
	virtual void workOn(PassengerCompartment& work_place){};

	virtual void report(const CargoBay& work_place){};
	virtual void report(const EquipmentCompartment& work_place){};
	virtual void report(const PassengerCompartment& work_place){};

	virtual bool equal(const Employee& sec)const;
	virtual String toString()const;
	virtual Employee* clone()const=0;
	String* get_name()const;
};

///////////////////////////////////////SecurityEmployee
class SecurityEmployee: public Employee{//all
public:
	SecurityEmployee(const String& nam);
	~SecurityEmployee();

	void workOn(CargoBay& work_place);
	void workOn(EquipmentCompartment& work_place);
	void workOn(PassengerCompartment& work_place);

	void report(const CargoBay& work_place)const;
	void report(const EquipmentCompartment& work_place)const;
	void report(const PassengerCompartment& work_place)const;


	bool equal(const SecurityEmployee& sec)const;
	SecurityEmployee* clone()const;
	String toString()const;
};

///////////////////////////////////////MaintenanceEmployee
class MaintenanceEmployee: public Employee{//cargobay, EquipmentCompartment
public:
	MaintenanceEmployee(const String& nam);
	~MaintenanceEmployee();

	void workOn(CargoBay& work_place);
	void workOn(EquipmentCompartment& work_place);

	void report(const CargoBay& work_place)const;
	void report(const EquipmentCompartment& work_place)const;

	bool equal(const MaintenanceEmployee& sec)const;
	MaintenanceEmployee* clone()const;
	String toString()const;
};

///////////////////////////////////////CleaningEmployee
class CleaningEmployee: public Employee{//CargoBay, PassengerCompartment
public:
	CleaningEmployee(const String nam);
	~CleaningEmployee();

	void workOn(CargoBay& work_place);
	void workOn(PassengerCompartment& work_place);
	void workOn(PrivateCompartment& work_place);

	void report(const CargoBay& work_place)const;
	void report(const PassengerCompartment& work_place)const;
	void report(const PrivateCompartment& work_place)const;

	String toString()const;

	bool equal(const CleaningEmployee& sec)const;
	CleaningEmployee* clone()const;
};

///////////////////////////////////////PlaneComponent
class PlaneComponent: public Object{
public:
	PlaneComponent();
	virtual ~PlaneComponent();

	virtual void process(SecurityEmployee& worker){};
	virtual void process(CleaningEmployee& worker){};
	virtual void process(MaintenanceEmployee& worker){};

	virtual bool equal(const PlaneComponent& sec)const;
	virtual String toString()const;
	virtual PlaneComponent* clone()const=0;
	virtual bool ready_check()const=0;
};

///////////////////////////////////////PassengerCompartment
class PassengerCompartment: public PlaneComponent{
	PassengerCompartment* Sub_PassCompartment;
	bool SecWorker;
	bool CleanWorker;
public:
	PassengerCompartment();
	PassengerCompartment(bool subs);
	~PassengerCompartment();

	void process(SecurityEmployee& worker);
	void process(CleaningEmployee& worker);

	bool equal(const PassengerCompartment& sec)const;
	PassengerCompartment* clone()const;
	bool ready_check()const;
	String toString()const;

	PassengerCompartment* get_SubPass()const;
	bool get_SecWork()const;
	bool get_CleanWork()const;
};

///////////////////////////////////////PrivateCompartment
class PrivateCompartment: public PlaneComponent{
protected:
	bool SecWorker;
	bool CleanWorker;
public:
	PrivateCompartment();
	~PrivateCompartment();

	virtual void process(SecurityEmployee& worker);
	virtual void process(CleaningEmployee& worker);

	bool equal(const PrivateCompartment& sec)const;
	virtual bool ready_check()const;
	String toString()const;
	virtual PrivateCompartment* clone()const=0;

	bool get_SecWork()const;
	bool get_CleanWork()const;
};

///////////////////////////////////////EquipmentCompartment
class EquipmentCompartment: public PrivateCompartment{
	bool SecWorker;
	bool MaintWorker;
public:
	EquipmentCompartment();
	~EquipmentCompartment();

	void process(SecurityEmployee& worker);
	void process(MaintenanceEmployee& worker);
	void process(CleaningEmployee& worker);

	bool equal(const EquipmentCompartment& sec)const;
	EquipmentCompartment* clone()const;
	bool ready_check()const;
	String toString()const;

	bool get_SecWork()const;
	bool get_MaintWork()const;
};

///////////////////////////////////////CargoBay
class CargoBay: public PrivateCompartment{
	EquipmentCompartment* equipment_space;
	bool SecWorker;
	bool CleanWorker;
	bool MaintWorker;
public:
	CargoBay();
	~CargoBay();

	void process(SecurityEmployee& worker);
	void process(CleaningEmployee& worker);
	void process(MaintenanceEmployee& worker);

	bool equal(const CargoBay& sec)const;
	String toString()const;
	bool ready_check()const;
	CargoBay* clone()const;

	EquipmentCompartment* get_equip_space()const;
	bool get_SecWork()const;
	bool get_CleanWork()const;
	bool get_MaintWork()const;
};

///////////////////////////////////////Plane
class Plane: public Object{
	String* title;
	int max_pl;
	int size_PassComp;
	CargoBay* cargo;
	EquipmentCompartment* e1;
	EquipmentCompartment* e2;
	EquipmentCompartment* e3;
	PassengerCompartment** pl_PassComp;
public:
	Plane(const String& titl, const int ma_pl=40);
	Plane();
	~Plane();

	void process(SecurityEmployee& worker);
	void process(MaintenanceEmployee& worker);
	void process(CleaningEmployee& worker);

	bool equal(const Plane& sec)const;
	bool ready_check()const;
	String toString()const;
	Plane* clone()const;

	String* get_title()const;
	int get_max_pl()const;
	int get_size_passcomp()const;
	CargoBay* get_cargo()const;
	EquipmentCompartment* get_e1()const;
	EquipmentCompartment* get_e2()const;
	EquipmentCompartment* get_e3()const;
	PassengerCompartment** get_pl_passcomp()const;
};

void clone_encrypt_and_print(const Object& sec);
