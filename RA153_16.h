/*----- PROTECTED REGION ID(RA153_16.h) ENABLED START -----*/
//=============================================================================
//
// file :        RA153_16.h
//
// description : Include file for the RA153_16 class
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


#ifndef RA153_16_H
#define RA153_16_H

#include <tango.h>
#include "SerialPort.h"
#include "Pneumatics.h"


/*----- PROTECTED REGION END -----*/	//	RA153_16.h

/**
 *  RA153_16 class description:
 *    
 */

namespace RA153_16_ns
{
/*----- PROTECTED REGION ID(RA153_16::Additional Class Declarations) ENABLED START -----*/

//	Additional Class Declarations

/*----- PROTECTED REGION END -----*/	//	RA153_16::Additional Class Declarations

class RA153_16 : public TANGO_BASE_CLASS
{

/*----- PROTECTED REGION ID(RA153_16::Data Members) ENABLED START -----*/

public:
	SP::SerialPort *sp;
	Pneumatics *pneumo;


/*----- PROTECTED REGION END -----*/	//	RA153_16::Data Members

//	Device property data members
public:
	//	SerailPort:	just path to system serial port
	string	serailPort;
	//	Axis:	number of motor
	Tango::DevShort	axis;
	//	Valve:	Number of Valve [0..16]
	Tango::DevShort	valve;
	//	MotorOrValve:	if this motor, then value need set to true
	//  if this valve, then value set to false
	Tango::DevBoolean	motorOrValve;
	//	DeviceAddr:	3 char addr, such as 081, 086, ..etc
	string	deviceAddr;

//	Attribute data members
public:
	Tango::DevBoolean	*attr_Valve_read;
	Tango::DevDouble	*attr_rPosition_read;
	Tango::DevDouble	*attr_aPosition_read;

//	Constructors and destructors
public:
	/**
	 * Constructs a newly device object.
	 *
	 *	@param cl	Class.
	 *	@param s 	Device Name
	 */
	RA153_16(Tango::DeviceClass *cl,string &s);
	/**
	 * Constructs a newly device object.
	 *
	 *	@param cl	Class.
	 *	@param s 	Device Name
	 */
	RA153_16(Tango::DeviceClass *cl,const char *s);
	/**
	 * Constructs a newly device object.
	 *
	 *	@param cl	Class.
	 *	@param s 	Device name
	 *	@param d	Device description.
	 */
	RA153_16(Tango::DeviceClass *cl,const char *s,const char *d);
	/**
	 * The device object destructor.
	 */
	~RA153_16() {delete_device();};


//	Miscellaneous methods
public:
	/*
	 *	will be called at device destruction or at init command.
	 */
	void delete_device();
	/*
	 *	Initialize the device
	 */
	virtual void init_device();
	/*
	 *	Read the device properties from database
	 */
	void get_device_property();
	/*
	 *	Always executed method before execution command method.
	 */
	virtual void always_executed_hook();


//	Attribute methods
public:
	//--------------------------------------------------------
	/*
	 *	Method      : RA153_16::read_attr_hardware()
	 *	Description : Hardware acquisition for attributes.
	 */
	//--------------------------------------------------------
	virtual void read_attr_hardware(vector<long> &attr_list);
	//--------------------------------------------------------
	/*
	 *	Method      : RA153_16::write_attr_hardware()
	 *	Description : Hardware writing for attributes.
	 */
	//--------------------------------------------------------
	virtual void write_attr_hardware(vector<long> &attr_list);

/**
 *	Attribute Valve related methods
 *	Description: 
 *
 *	Data type:	Tango::DevBoolean
 *	Attr type:	Scalar
 */
	virtual void read_Valve(Tango::Attribute &attr);
	virtual void write_Valve(Tango::WAttribute &attr);
	virtual bool is_Valve_allowed(Tango::AttReqType type);
/**
 *	Attribute rPosition related methods
 *	Description: Reletively position
 *
 *	Data type:	Tango::DevDouble
 *	Attr type:	Scalar
 */
	virtual void read_rPosition(Tango::Attribute &attr);
	virtual void write_rPosition(Tango::WAttribute &attr);
	virtual bool is_rPosition_allowed(Tango::AttReqType type);
/**
 *	Attribute aPosition related methods
 *	Description: Absolute position
 *
 *	Data type:	Tango::DevDouble
 *	Attr type:	Scalar
 */
	virtual void read_aPosition(Tango::Attribute &attr);
	virtual void write_aPosition(Tango::WAttribute &attr);
	virtual bool is_aPosition_allowed(Tango::AttReqType type);


	//--------------------------------------------------------
	/**
	 *	Method      : RA153_16::add_dynamic_attributes()
	 *	Description : Add dynamic attributes if any.
	 */
	//--------------------------------------------------------
	void add_dynamic_attributes();




//	Command related methods
public:


	//--------------------------------------------------------
	/**
	 *	Method      : RA153_16::add_dynamic_commands()
	 *	Description : Add dynamic commands if any.
	 */
	//--------------------------------------------------------
	void add_dynamic_commands();

/*----- PROTECTED REGION ID(RA153_16::Additional Method prototypes) ENABLED START -----*/

	// methods...

/*----- PROTECTED REGION END -----*/	//	RA153_16::Additional Method prototypes
};

/*----- PROTECTED REGION ID(RA153_16::Additional Classes Definitions) ENABLED START -----*/

//	Additional Classes Definitions

/*----- PROTECTED REGION END -----*/	//	RA153_16::Additional Classes Definitions

}	//	End of namespace

#endif   //	RA153_16_H
