/*----- PROTECTED REGION ID(RA153_16Class.cpp) ENABLED START -----*/
//=============================================================================
//
// file :        RA153_16Class.cpp
//
// description : C++ source for the RA153_16Class.
//               A singleton class derived from DeviceClass.
//               It implements the command and attribute list
//               and all properties and methods required
//               by the RA153_16 once per process.
//
// project :     
//
// This file is part of Tango device class.
// 
// Tango is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// Tango is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with Tango.  If not, see <http://www.gnu.org/licenses/>.
// 
//
// Kirill Pshenichnyi PNPI Gatchina (c) 2019
//
//=============================================================================
//                This file is generated by POGO
//        (Program Obviously used to Generate tango Object)
//=============================================================================


#include <RA153_16Class.h>

/*----- PROTECTED REGION END -----*/	//	RA153_16Class.cpp

//-------------------------------------------------------------------
/**
 *	Create RA153_16Class singleton and
 *	return it in a C function for Python usage
 */
//-------------------------------------------------------------------
extern "C" {
#ifdef _TG_WINDOWS_

__declspec(dllexport)

#endif

	Tango::DeviceClass *_create_RA153_16_class(const char *name) {
		return RA153_16_ns::RA153_16Class::init(name);
	}
}

namespace RA153_16_ns
{
//===================================================================
//	Initialize pointer for singleton pattern
//===================================================================
RA153_16Class *RA153_16Class::_instance = NULL;

//--------------------------------------------------------
/**
 * method : 		RA153_16Class::RA153_16Class(string &s)
 * description : 	constructor for the RA153_16Class
 *
 * @param s	The class name
 */
//--------------------------------------------------------
RA153_16Class::RA153_16Class(string &s):Tango::DeviceClass(s)
{
	cout2 << "Entering RA153_16Class constructor" << endl;
	set_default_property();
	write_class_property();

	/*----- PROTECTED REGION ID(RA153_16Class::constructor) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	RA153_16Class::constructor

	cout2 << "Leaving RA153_16Class constructor" << endl;
}

//--------------------------------------------------------
/**
 * method : 		RA153_16Class::~RA153_16Class()
 * description : 	destructor for the RA153_16Class
 */
//--------------------------------------------------------
RA153_16Class::~RA153_16Class()
{
	/*----- PROTECTED REGION ID(RA153_16Class::destructor) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	RA153_16Class::destructor

	_instance = NULL;
}


//--------------------------------------------------------
/**
 * method : 		RA153_16Class::init
 * description : 	Create the object if not already done.
 *                  Otherwise, just return a pointer to the object
 *
 * @param	name	The class name
 */
//--------------------------------------------------------
RA153_16Class *RA153_16Class::init(const char *name)
{
	if (_instance == NULL)
	{
		try
		{
			string s(name);
			_instance = new RA153_16Class(s);
		}
		catch (bad_alloc &)
		{
			throw;
		}
	}
	return _instance;
}

//--------------------------------------------------------
/**
 * method : 		RA153_16Class::instance
 * description : 	Check if object already created,
 *                  and return a pointer to the object
 */
//--------------------------------------------------------
RA153_16Class *RA153_16Class::instance()
{
	if (_instance == NULL)
	{
		cerr << "Class is not initialised !!" << endl;
		exit(-1);
	}
	return _instance;
}



//===================================================================
//	Command execution method calls
//===================================================================

//===================================================================
//	Properties management
//===================================================================
//--------------------------------------------------------
/**
 *	Method      : RA153_16Class::get_class_property()
 *	Description : Get the class property for specified name.
 */
//--------------------------------------------------------
Tango::DbDatum RA153_16Class::get_class_property(string &prop_name)
{
	for (unsigned int i=0 ; i<cl_prop.size() ; i++)
		if (cl_prop[i].name == prop_name)
			return cl_prop[i];
	//	if not found, returns  an empty DbDatum
	return Tango::DbDatum(prop_name);
}

//--------------------------------------------------------
/**
 *	Method      : RA153_16Class::get_default_device_property()
 *	Description : Return the default value for device property.
 */
//--------------------------------------------------------
Tango::DbDatum RA153_16Class::get_default_device_property(string &prop_name)
{
	for (unsigned int i=0 ; i<dev_def_prop.size() ; i++)
		if (dev_def_prop[i].name == prop_name)
			return dev_def_prop[i];
	//	if not found, return  an empty DbDatum
	return Tango::DbDatum(prop_name);
}

//--------------------------------------------------------
/**
 *	Method      : RA153_16Class::get_default_class_property()
 *	Description : Return the default value for class property.
 */
//--------------------------------------------------------
Tango::DbDatum RA153_16Class::get_default_class_property(string &prop_name)
{
	for (unsigned int i=0 ; i<cl_def_prop.size() ; i++)
		if (cl_def_prop[i].name == prop_name)
			return cl_def_prop[i];
	//	if not found, return  an empty DbDatum
	return Tango::DbDatum(prop_name);
}


//--------------------------------------------------------
/**
 *	Method      : RA153_16Class::set_default_property()
 *	Description : Set default property (class and device) for wizard.
 *                For each property, add to wizard property name and description.
 *                If default value has been set, add it to wizard property and
 *                store it in a DbDatum.
 */
//--------------------------------------------------------
void RA153_16Class::set_default_property()
{
	string	prop_name;
	string	prop_desc;
	string	prop_def;
	vector<string>	vect_data;

	//	Set Default Class Properties

	//	Set Default device Properties
	prop_name = "SerailPort";
	prop_desc = "just path to system serial port";
	prop_def  = "/dev/ttyS0";
	vect_data.clear();
	vect_data.push_back("/dev/ttyS0");
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);
	prop_name = "Axis";
	prop_desc = "number of motor";
	prop_def  = "0";
	vect_data.clear();
	vect_data.push_back("0");
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);
	prop_name = "Valve";
	prop_desc = "Number of Valve";
	prop_def  = "0";
	vect_data.clear();
	vect_data.push_back("0");
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);
	prop_name = "MotorOrValve";
	prop_desc = "if this motor, then value need set to true\nif this valve, then value set to false";
	prop_def  = "true";
	vect_data.clear();
	vect_data.push_back("true");
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);
}

//--------------------------------------------------------
/**
 *	Method      : RA153_16Class::write_class_property()
 *	Description : Set class description fields as property in database
 */
//--------------------------------------------------------
void RA153_16Class::write_class_property()
{
	//	First time, check if database used
	if (Tango::Util::_UseDb == false)
		return;

	Tango::DbData	data;
	string	classname = get_name();
	string	header;
	string::size_type	start, end;

	//	Put title
	Tango::DbDatum	title("ProjectTitle");
	string	str_title("");
	title << str_title;
	data.push_back(title);

	//	Put Description
	Tango::DbDatum	description("Description");
	vector<string>	str_desc;
	str_desc.push_back("");
	description << str_desc;
	data.push_back(description);

	//  Put inheritance
	Tango::DbDatum	inher_datum("InheritedFrom");
	vector<string> inheritance;
	inheritance.push_back("TANGO_BASE_CLASS");
	inher_datum << inheritance;
	data.push_back(inher_datum);

	//	Call database and and values
	get_db_class()->put_property(data);
}

//===================================================================
//	Factory methods
//===================================================================

//--------------------------------------------------------
/**
 *	Method      : RA153_16Class::device_factory()
 *	Description : Create the device object(s)
 *                and store them in the device list
 */
//--------------------------------------------------------
void RA153_16Class::device_factory(const Tango::DevVarStringArray *devlist_ptr)
{
	/*----- PROTECTED REGION ID(RA153_16Class::device_factory_before) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	RA153_16Class::device_factory_before

	//	Create devices and add it into the device list
	for (unsigned long i=0 ; i<devlist_ptr->length() ; i++)
	{
		cout4 << "Device name : " << (*devlist_ptr)[i].in() << endl;
		device_list.push_back(new RA153_16(this, (*devlist_ptr)[i]));
	}

	//	Manage dynamic attributes if any
	erase_dynamic_attributes(devlist_ptr, get_class_attr()->get_attr_list());

	//	Export devices to the outside world
	for (unsigned long i=1 ; i<=devlist_ptr->length() ; i++)
	{
		//	Add dynamic attributes if any
		RA153_16 *dev = static_cast<RA153_16 *>(device_list[device_list.size()-i]);
		dev->add_dynamic_attributes();

		//	Check before if database used.
		if ((Tango::Util::_UseDb == true) && (Tango::Util::_FileDb == false))
			export_device(dev);
		else
			export_device(dev, dev->get_name().c_str());
	}

	/*----- PROTECTED REGION ID(RA153_16Class::device_factory_after) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	RA153_16Class::device_factory_after
}
//--------------------------------------------------------
/**
 *	Method      : RA153_16Class::attribute_factory()
 *	Description : Create the attribute object(s)
 *                and store them in the attribute list
 */
//--------------------------------------------------------
void RA153_16Class::attribute_factory(vector<Tango::Attr *> &att_list)
{
	/*----- PROTECTED REGION ID(RA153_16Class::attribute_factory_before) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	RA153_16Class::attribute_factory_before
	//	Attribute : Valve
	ValveAttrib	*valve = new ValveAttrib();
	Tango::UserDefaultAttrProp	valve_prop;
	//	description	not set for Valve
	//	label	not set for Valve
	//	unit	not set for Valve
	//	standard_unit	not set for Valve
	//	display_unit	not set for Valve
	//	format	not set for Valve
	//	max_value	not set for Valve
	//	min_value	not set for Valve
	//	max_alarm	not set for Valve
	//	min_alarm	not set for Valve
	//	max_warning	not set for Valve
	//	min_warning	not set for Valve
	//	delta_t	not set for Valve
	//	delta_val	not set for Valve
	
	valve->set_default_properties(valve_prop);
	valve->set_polling_period(1000);
	valve->set_disp_level(Tango::OPERATOR);
	//	Not Memorized
	att_list.push_back(valve);


	//	Create a list of static attributes
	create_static_attribute_list(get_class_attr()->get_attr_list());
	/*----- PROTECTED REGION ID(RA153_16Class::attribute_factory_after) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	RA153_16Class::attribute_factory_after
}
//--------------------------------------------------------
/**
 *	Method      : RA153_16Class::pipe_factory()
 *	Description : Create the pipe object(s)
 *                and store them in the pipe list
 */
//--------------------------------------------------------
void RA153_16Class::pipe_factory()
{
	/*----- PROTECTED REGION ID(RA153_16Class::pipe_factory_before) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	RA153_16Class::pipe_factory_before
	/*----- PROTECTED REGION ID(RA153_16Class::pipe_factory_after) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	RA153_16Class::pipe_factory_after
}
//--------------------------------------------------------
/**
 *	Method      : RA153_16Class::command_factory()
 *	Description : Create the command object(s)
 *                and store them in the command list
 */
//--------------------------------------------------------
void RA153_16Class::command_factory()
{
	/*----- PROTECTED REGION ID(RA153_16Class::command_factory_before) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	RA153_16Class::command_factory_before


	/*----- PROTECTED REGION ID(RA153_16Class::command_factory_after) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	RA153_16Class::command_factory_after
}

//===================================================================
//	Dynamic attributes related methods
//===================================================================

//--------------------------------------------------------
/**
 * method : 		RA153_16Class::create_static_attribute_list
 * description : 	Create the a list of static attributes
 *
 * @param	att_list	the ceated attribute list
 */
//--------------------------------------------------------
void RA153_16Class::create_static_attribute_list(vector<Tango::Attr *> &att_list)
{
	for (unsigned long i=0 ; i<att_list.size() ; i++)
	{
		string att_name(att_list[i]->get_name());
		transform(att_name.begin(), att_name.end(), att_name.begin(), ::tolower);
		defaultAttList.push_back(att_name);
	}

	cout2 << defaultAttList.size() << " attributes in default list" << endl;

	/*----- PROTECTED REGION ID(RA153_16Class::create_static_att_list) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	RA153_16Class::create_static_att_list
}


//--------------------------------------------------------
/**
 * method : 		RA153_16Class::erase_dynamic_attributes
 * description : 	delete the dynamic attributes if any.
 *
 * @param	devlist_ptr	the device list pointer
 * @param	list of all attributes
 */
//--------------------------------------------------------
void RA153_16Class::erase_dynamic_attributes(const Tango::DevVarStringArray *devlist_ptr, vector<Tango::Attr *> &att_list)
{
	Tango::Util *tg = Tango::Util::instance();

	for (unsigned long i=0 ; i<devlist_ptr->length() ; i++)
	{
		Tango::DeviceImpl *dev_impl = tg->get_device_by_name(((string)(*devlist_ptr)[i]).c_str());
		RA153_16 *dev = static_cast<RA153_16 *> (dev_impl);

		vector<Tango::Attribute *> &dev_att_list = dev->get_device_attr()->get_attribute_list();
		vector<Tango::Attribute *>::iterator ite_att;
		for (ite_att=dev_att_list.begin() ; ite_att != dev_att_list.end() ; ++ite_att)
		{
			string att_name((*ite_att)->get_name_lower());
			if ((att_name == "state") || (att_name == "status"))
				continue;
			vector<string>::iterator ite_str = find(defaultAttList.begin(), defaultAttList.end(), att_name);
			if (ite_str == defaultAttList.end())
			{
				cout2 << att_name << " is a UNWANTED dynamic attribute for device " << (*devlist_ptr)[i] << endl;
				Tango::Attribute &att = dev->get_device_attr()->get_attr_by_name(att_name.c_str());
				dev->remove_attribute(att_list[att.get_attr_idx()], true, false);
				--ite_att;
			}
		}
	}
	/*----- PROTECTED REGION ID(RA153_16Class::erase_dynamic_attributes) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	RA153_16Class::erase_dynamic_attributes
}

//--------------------------------------------------------
/**
 *	Method      : RA153_16Class::get_attr_by_name()
 *	Description : returns Tango::Attr * object found by name
 */
//--------------------------------------------------------
Tango::Attr *RA153_16Class::get_attr_object_by_name(vector<Tango::Attr *> &att_list, string attname)
{
	vector<Tango::Attr *>::iterator it;
	for (it=att_list.begin() ; it<att_list.end() ; ++it)
		if ((*it)->get_name()==attname)
			return (*it);
	//	Attr does not exist
	return NULL;
}


/*----- PROTECTED REGION ID(RA153_16Class::Additional Methods) ENABLED START -----*/

/*----- PROTECTED REGION END -----*/	//	RA153_16Class::Additional Methods
} //	namespace
