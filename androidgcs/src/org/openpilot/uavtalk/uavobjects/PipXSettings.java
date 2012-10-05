/**
 ******************************************************************************
 *
 * @file       uavobjecttemplate.cpp
 * @author     The OpenPilot Team, http://www.openpilot.org Copyright (C) 2010.
 * @brief      Template for an uavobject in java
 *             This is a autogenerated file!! Do not modify and expect a result.
 *             PipXtreme configurations options.
 *
 * @see        The GNU Public License (GPL) Version 3
 *
 *****************************************************************************/
/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

package org.openpilot.uavtalk.uavobjects;

import java.nio.ByteBuffer;
import java.util.ArrayList;
import java.util.List;
import java.util.ListIterator;

import org.openpilot.uavtalk.UAVObjectManager;
import org.openpilot.uavtalk.UAVObject;
import org.openpilot.uavtalk.UAVDataObject;
import org.openpilot.uavtalk.UAVObjectField;

/**
PipXtreme configurations options.

generated from pipxsettings.xml
 **/
public class PipXSettings extends UAVDataObject {

	public PipXSettings() {
		super(OBJID, ISSINGLEINST, ISSETTINGS, NAME);
		
		List<UAVObjectField> fields = new ArrayList<UAVObjectField>();
		

		List<String> PairIDElemNames = new ArrayList<String>();
		PairIDElemNames.add("0");
		fields.add( new UAVObjectField("PairID", "", UAVObjectField.FieldType.UINT32, PairIDElemNames, null) );

		List<String> FrequencyElemNames = new ArrayList<String>();
		FrequencyElemNames.add("0");
		fields.add( new UAVObjectField("Frequency", "", UAVObjectField.FieldType.UINT32, FrequencyElemNames, null) );

		List<String> SendTimeoutElemNames = new ArrayList<String>();
		SendTimeoutElemNames.add("0");
		fields.add( new UAVObjectField("SendTimeout", "ms", UAVObjectField.FieldType.UINT16, SendTimeoutElemNames, null) );

		List<String> TelemetryConfigElemNames = new ArrayList<String>();
		TelemetryConfigElemNames.add("0");
		List<String> TelemetryConfigEnumOptions = new ArrayList<String>();
		TelemetryConfigEnumOptions.add("Disabled");
		TelemetryConfigEnumOptions.add("Serial");
		TelemetryConfigEnumOptions.add("UAVTalk");
		TelemetryConfigEnumOptions.add("GCS");
		TelemetryConfigEnumOptions.add("Debug");
		fields.add( new UAVObjectField("TelemetryConfig", "function", UAVObjectField.FieldType.ENUM, TelemetryConfigElemNames, TelemetryConfigEnumOptions) );

		List<String> TelemetrySpeedElemNames = new ArrayList<String>();
		TelemetrySpeedElemNames.add("0");
		List<String> TelemetrySpeedEnumOptions = new ArrayList<String>();
		TelemetrySpeedEnumOptions.add("2400");
		TelemetrySpeedEnumOptions.add("4800");
		TelemetrySpeedEnumOptions.add("9600");
		TelemetrySpeedEnumOptions.add("19200");
		TelemetrySpeedEnumOptions.add("38400");
		TelemetrySpeedEnumOptions.add("57600");
		TelemetrySpeedEnumOptions.add("115200");
		fields.add( new UAVObjectField("TelemetrySpeed", "bps", UAVObjectField.FieldType.ENUM, TelemetrySpeedElemNames, TelemetrySpeedEnumOptions) );

		List<String> FlexiConfigElemNames = new ArrayList<String>();
		FlexiConfigElemNames.add("0");
		List<String> FlexiConfigEnumOptions = new ArrayList<String>();
		FlexiConfigEnumOptions.add("Disabled");
		FlexiConfigEnumOptions.add("Serial");
		FlexiConfigEnumOptions.add("UAVTalk");
		FlexiConfigEnumOptions.add("GCS");
		FlexiConfigEnumOptions.add("PPM_In");
		FlexiConfigEnumOptions.add("PPM_Out");
		FlexiConfigEnumOptions.add("RSSI");
		FlexiConfigEnumOptions.add("Debug");
		fields.add( new UAVObjectField("FlexiConfig", "function", UAVObjectField.FieldType.ENUM, FlexiConfigElemNames, FlexiConfigEnumOptions) );

		List<String> FlexiSpeedElemNames = new ArrayList<String>();
		FlexiSpeedElemNames.add("0");
		List<String> FlexiSpeedEnumOptions = new ArrayList<String>();
		FlexiSpeedEnumOptions.add("2400");
		FlexiSpeedEnumOptions.add("4800");
		FlexiSpeedEnumOptions.add("9600");
		FlexiSpeedEnumOptions.add("19200");
		FlexiSpeedEnumOptions.add("38400");
		FlexiSpeedEnumOptions.add("57600");
		FlexiSpeedEnumOptions.add("115200");
		fields.add( new UAVObjectField("FlexiSpeed", "bps", UAVObjectField.FieldType.ENUM, FlexiSpeedElemNames, FlexiSpeedEnumOptions) );

		List<String> VCPConfigElemNames = new ArrayList<String>();
		VCPConfigElemNames.add("0");
		List<String> VCPConfigEnumOptions = new ArrayList<String>();
		VCPConfigEnumOptions.add("Disabled");
		VCPConfigEnumOptions.add("Serial");
		VCPConfigEnumOptions.add("Debug");
		fields.add( new UAVObjectField("VCPConfig", "function", UAVObjectField.FieldType.ENUM, VCPConfigElemNames, VCPConfigEnumOptions) );

		List<String> VCPSpeedElemNames = new ArrayList<String>();
		VCPSpeedElemNames.add("0");
		List<String> VCPSpeedEnumOptions = new ArrayList<String>();
		VCPSpeedEnumOptions.add("2400");
		VCPSpeedEnumOptions.add("4800");
		VCPSpeedEnumOptions.add("9600");
		VCPSpeedEnumOptions.add("19200");
		VCPSpeedEnumOptions.add("38400");
		VCPSpeedEnumOptions.add("57600");
		VCPSpeedEnumOptions.add("115200");
		fields.add( new UAVObjectField("VCPSpeed", "bps", UAVObjectField.FieldType.ENUM, VCPSpeedElemNames, VCPSpeedEnumOptions) );

		List<String> RFSpeedElemNames = new ArrayList<String>();
		RFSpeedElemNames.add("0");
		List<String> RFSpeedEnumOptions = new ArrayList<String>();
		RFSpeedEnumOptions.add("2400");
		RFSpeedEnumOptions.add("4800");
		RFSpeedEnumOptions.add("9600");
		RFSpeedEnumOptions.add("19200");
		RFSpeedEnumOptions.add("38400");
		RFSpeedEnumOptions.add("57600");
		RFSpeedEnumOptions.add("115200");
		fields.add( new UAVObjectField("RFSpeed", "bps", UAVObjectField.FieldType.ENUM, RFSpeedElemNames, RFSpeedEnumOptions) );

		List<String> MaxRFPowerElemNames = new ArrayList<String>();
		MaxRFPowerElemNames.add("0");
		List<String> MaxRFPowerEnumOptions = new ArrayList<String>();
		MaxRFPowerEnumOptions.add("1.25");
		MaxRFPowerEnumOptions.add("1.6");
		MaxRFPowerEnumOptions.add("3.16");
		MaxRFPowerEnumOptions.add("6.3");
		MaxRFPowerEnumOptions.add("12.6");
		MaxRFPowerEnumOptions.add("25");
		MaxRFPowerEnumOptions.add("50");
		MaxRFPowerEnumOptions.add("100");
		fields.add( new UAVObjectField("MaxRFPower", "mW", UAVObjectField.FieldType.ENUM, MaxRFPowerElemNames, MaxRFPowerEnumOptions) );

		List<String> MinPacketSizeElemNames = new ArrayList<String>();
		MinPacketSizeElemNames.add("0");
		fields.add( new UAVObjectField("MinPacketSize", "bytes", UAVObjectField.FieldType.UINT8, MinPacketSizeElemNames, null) );

		List<String> FrequencyCalibrationElemNames = new ArrayList<String>();
		FrequencyCalibrationElemNames.add("0");
		fields.add( new UAVObjectField("FrequencyCalibration", "", UAVObjectField.FieldType.UINT8, FrequencyCalibrationElemNames, null) );

		List<String> AESKeyElemNames = new ArrayList<String>();
		AESKeyElemNames.add("0");
		AESKeyElemNames.add("1");
		AESKeyElemNames.add("2");
		AESKeyElemNames.add("3");
		AESKeyElemNames.add("4");
		AESKeyElemNames.add("5");
		AESKeyElemNames.add("6");
		AESKeyElemNames.add("7");
		AESKeyElemNames.add("8");
		AESKeyElemNames.add("9");
		AESKeyElemNames.add("10");
		AESKeyElemNames.add("11");
		AESKeyElemNames.add("12");
		AESKeyElemNames.add("13");
		AESKeyElemNames.add("14");
		AESKeyElemNames.add("15");
		AESKeyElemNames.add("16");
		AESKeyElemNames.add("17");
		AESKeyElemNames.add("18");
		AESKeyElemNames.add("19");
		AESKeyElemNames.add("20");
		AESKeyElemNames.add("21");
		AESKeyElemNames.add("22");
		AESKeyElemNames.add("23");
		AESKeyElemNames.add("24");
		AESKeyElemNames.add("25");
		AESKeyElemNames.add("26");
		AESKeyElemNames.add("27");
		AESKeyElemNames.add("28");
		AESKeyElemNames.add("29");
		AESKeyElemNames.add("30");
		AESKeyElemNames.add("31");
		fields.add( new UAVObjectField("AESKey", "", UAVObjectField.FieldType.UINT8, AESKeyElemNames, null) );


		// Compute the number of bytes for this object
		int numBytes = 0;
		ListIterator<UAVObjectField> li = fields.listIterator();
		while(li.hasNext()) {
			numBytes += li.next().getNumBytes();
		}
		NUMBYTES = numBytes;

		// Initialize object
		initializeFields(fields, ByteBuffer.allocate(NUMBYTES), NUMBYTES);
		// Set the default field values
		setDefaultFieldValues();
		// Set the object description
		setDescription(DESCRIPTION);
	}

	/**
	 * Create a Metadata object filled with default values for this object
	 * @return Metadata object with default values
	 */
	public Metadata getDefaultMetadata() {
		UAVObject.Metadata metadata = new UAVObject.Metadata();
    	metadata.flags =
		    UAVObject.Metadata.AccessModeNum(UAVObject.AccessMode.ACCESS_READWRITE) << UAVOBJ_ACCESS_SHIFT |
		    UAVObject.Metadata.AccessModeNum(UAVObject.AccessMode.ACCESS_READWRITE) << UAVOBJ_GCS_ACCESS_SHIFT |
		    1 << UAVOBJ_TELEMETRY_ACKED_SHIFT |
		    1 << UAVOBJ_GCS_TELEMETRY_ACKED_SHIFT |
		    UAVObject.Metadata.UpdateModeNum(UAVObject.UpdateMode.UPDATEMODE_ONCHANGE) << UAVOBJ_TELEMETRY_UPDATE_MODE_SHIFT |
		    UAVObject.Metadata.UpdateModeNum(UAVObject.UpdateMode.UPDATEMODE_ONCHANGE) << UAVOBJ_GCS_TELEMETRY_UPDATE_MODE_SHIFT;
    	metadata.flightTelemetryUpdatePeriod = 0;
    	metadata.gcsTelemetryUpdatePeriod = 0;
    	metadata.loggingUpdatePeriod = 0;
 
		return metadata;
	}

	/**
	 * Initialize object fields with the default values.
	 * If a default value is not specified the object fields
	 * will be initialized to zero.
	 */
	public void setDefaultFieldValues()
	{
		getField("PairID").setValue(0);
		getField("Frequency").setValue(434000000);
		getField("SendTimeout").setValue(50);
		getField("TelemetryConfig").setValue("UAVTalk");
		getField("TelemetrySpeed").setValue("57600");
		getField("FlexiConfig").setValue("Disabled");
		getField("FlexiSpeed").setValue("57600");
		getField("VCPConfig").setValue("Disabled");
		getField("VCPSpeed").setValue("57600");
		getField("RFSpeed").setValue("115200");
		getField("MaxRFPower").setValue("1.25");
		getField("MinPacketSize").setValue(50);
		getField("FrequencyCalibration").setValue(127);
		getField("AESKey").setValue(0,0);
		getField("AESKey").setValue(0,1);
		getField("AESKey").setValue(0,2);
		getField("AESKey").setValue(0,3);
		getField("AESKey").setValue(0,4);
		getField("AESKey").setValue(0,5);
		getField("AESKey").setValue(0,6);
		getField("AESKey").setValue(0,7);
		getField("AESKey").setValue(0,8);
		getField("AESKey").setValue(0,9);
		getField("AESKey").setValue(0,10);
		getField("AESKey").setValue(0,11);
		getField("AESKey").setValue(0,12);
		getField("AESKey").setValue(0,13);
		getField("AESKey").setValue(0,14);
		getField("AESKey").setValue(0,15);
		getField("AESKey").setValue(0,16);
		getField("AESKey").setValue(0,17);
		getField("AESKey").setValue(0,18);
		getField("AESKey").setValue(0,19);
		getField("AESKey").setValue(0,20);
		getField("AESKey").setValue(0,21);
		getField("AESKey").setValue(0,22);
		getField("AESKey").setValue(0,23);
		getField("AESKey").setValue(0,24);
		getField("AESKey").setValue(0,25);
		getField("AESKey").setValue(0,26);
		getField("AESKey").setValue(0,27);
		getField("AESKey").setValue(0,28);
		getField("AESKey").setValue(0,29);
		getField("AESKey").setValue(0,30);
		getField("AESKey").setValue(0,31);

	}

	/**
	 * Create a clone of this object, a new instance ID must be specified.
	 * Do not use this function directly to create new instances, the
	 * UAVObjectManager should be used instead.
	 */
	public UAVDataObject clone(long instID) {
		// TODO: Need to get specific instance to clone
		try {
			PipXSettings obj = new PipXSettings();
			obj.initialize(instID, this.getMetaObject());
			return obj;
		} catch  (Exception e) {
			return null;
		}
	}

	/**
	 * Static function to retrieve an instance of the object.
	 */
	public PipXSettings GetInstance(UAVObjectManager objMngr, long instID)
	{
	    return (PipXSettings)(objMngr.getObject(PipXSettings.OBJID, instID));
	}

	// Constants
	protected static final long OBJID = 0xBA192BCAl;
	protected static final String NAME = "PipXSettings";
	protected static String DESCRIPTION = "PipXtreme configurations options.";
	protected static final boolean ISSINGLEINST = 1 > 0;
	protected static final boolean ISSETTINGS = 1 > 0;
	protected static int NUMBYTES = 0;


}
