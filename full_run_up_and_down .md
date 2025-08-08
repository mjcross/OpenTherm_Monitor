---- Opened the serial port COM3 ----
6
5
4
3
2
1
State machines loaded and running
Entering main loop

Controller:     0   3 0000      read      Slave Config / Member ID  00000000, 0 
Controller:     0   3 0000      read      Slave Config / Member ID  00000000, 0 
Controller:     0   3 0000      read      Slave Config / Member ID  00000000, 0 
Controller:     0   3 0000      read      Slave Config / Member ID  00000000, 0 
Controller:     0   3 0000      read      Slave Config / Member ID  00000000, 0 
Controller:     0   3 0000      read      Slave Config / Member ID  00000000, 0 
Controller:     0   3 0000      read      Slave Config / Member ID  00000000, 0 

# At this point I connected the boiler to the OT interface, but hadn't configured it to OpenTherm mode

Controller:     0   3 0000      read      Slave Config / Member ID  00000000, 0 
Boiler:         4   3 5021      read ACK  Slave Config / Member ID  01010000, 33    # Slave config: no DHW, on/off, no cooling, storage tank, MemberID 33 (Viessmann)
Controller:     0   3 0000      read      Slave Config / Member ID  00000000, 0 
Boiler:         4   3 5021      read ACK  Slave Config / Member ID  01010000, 33 
Controller:     0   3 0000      read      Slave Config / Member ID  00000000, 0 
Boiler:         4   3 5021      read ACK  Slave Config / Member ID  01010000, 33 
Controller:     0   3 0000      read      Slave Config / Member ID  00000000, 0 
Boiler:         4   3 5021      read ACK  Slave Config / Member ID  01010000, 33 
Controller:     1   2 009c      write     Master Config / Member ID  00000000, 156  # Master config: MemberID 156 (Tado)
Boiler:         5   2 009c      write ACK Master Config / Member ID  00000000, 156 
Controller:     0  48 0000      read      DHW setpoint upper & lower bounds for adjustment  0, 0 deg C
Boiler:         4  48 3c1e      read ACK  DHW setpoint upper & lower bounds for adjustment  60, 30 deg C
Controller:     0  48 0000      read      DHW setpoint upper & lower bounds for adjustment  0, 0 deg C
Boiler:         4  48 3c1e      read ACK  DHW setpoint upper & lower bounds for adjustment  60, 30 deg C
Controller:     0  48 0000      read      DHW setpoint upper & lower bounds for adjustment  0, 0 deg C
Boiler:         4  48 3c1e      read ACK  DHW setpoint upper & lower bounds for adjustment  60, 30 deg C
Controller:     0   6 0000      read      Remote-parameter flags  00000000, 00000000 
Boiler:         4   6 0202      read ACK  Remote-parameter flags  00000010, 00000010    # max CH setpoint is remotely accessable (read/write) 
Controller:     0  15 0000      read      Maximum boiler capacity (kW) / Minimum boiler modulation level(%)  0, 0 kW/%
Boiler:         4  15 190a      read ACK  Maximum boiler capacity (kW) / Minimum boiler modulation level(%)  25, 10 kW/%
Controller:     0  49 0000      read      Max CH water setpoint upper & lower bounds for adjustment  0, 0 deg C
Boiler:         4  49 5205      read ACK  Max CH water setpoint upper & lower bounds for adjustment  82, 5 deg C
Controller:     0  49 0000      read      Max CH water setpoint upper & lower bounds for adjustment  0, 0 deg C
Boiler:         4  49 5205      read ACK  Max CH water setpoint upper & lower bounds for adjustment  82, 5 deg C
Controller:     0  49 0000      read      Max CH water setpoint upper & lower bounds for adjustment  0, 0 deg C
Boiler:         4  49 5205      read ACK  Max CH water setpoint upper & lower bounds for adjustment  82, 5 deg C
Controller:     0  57 0000      read      Max CH water setpoint   0.00 deg C
Boiler:         4  57 5200      read ACK  Max CH water setpoint  82.00 deg C
Controller:     1  14 0000      write     Maximum relative modulation level setting   0.00 %
Boiler:         5  14 0000      write ACK Maximum relative modulation level setting   0.00 %
Controller:     0   0 0200      read      Master and Slave status  00000010, 00000000   # Master status: CH disabled, DHW enabled
Boiler:         4   0 020b      read ACK  Master and Slave status  00000010, 00001011   # Slave status: fault indicated, CH active, DHW not active, flame on
Controller:     0   0 0200      read      Master and Slave status  00000010, 00000000 
Boiler:         4   0 020b      read ACK  Master and Slave status  00000010, 00001011 
Controller:     0   0 0200      read      Master and Slave status  00000010, 00000000 
Boiler:         4   0 020b      read ACK  Master and Slave status  00000010, 00001011 
Controller:     0  26 0000      read      DHW temperature   0.00 deg C
Boiler:         6  26 0000      Data Ivld DHW temperature   0.00 deg C  # Slave recognises the command but has no valid data
Controller:     0  25 0000      read      Boiler water temperature   0.00 deg C
Boiler:         4  25 36e6      read ACK  Boiler water temperature  54.90 deg C
Controller:     0  17 0000      read      Relative Modulation Level   0.00 %
Boiler:         4  17 2700      read ACK  Relative Modulation Level  39.00 %
Controller:     1  16 1400      write     Room Setpoint  20.00 deg C
Boiler:         7  16 0000      Unk DatID Room Setpoint   0.00 deg C    # Slave doesn't recognise the command
Controller:     1  24 1bb5      write     Room Temperature  27.71 deg C
Boiler:         7  24 0000      Unk DatID Room Temperature   0.00 deg C
Controller:     1   1 0000      write     Control setpoint   0.00 deg C
Boiler:         5   1 3c00      write ACK Control setpoint  60.00 deg C
Controller:     1  14 6400      write     Maximum relative modulation level setting  100.00 %
Boiler:         5  14 6400      write ACK Maximum relative modulation level setting  100.00 %
Controller:     0   5 0000      read      Application-specific fault  00000000, 0 
Boiler:         4   5 01ff      read ACK  Application-specific fault  00000001, 255 # Slave reports "service required", code 255
Controller:     0  28 0000      read      Return water temperature   0.00 deg C
Boiler:         7  28 0000      Unk DatID Return water temperature   0.00 deg C
Controller:     0  18 0000      read      CH water pressure   0.00 bar
Boiler:         4  18 0133      read ACK  CH water pressure   1.20 bar
Controller:     0  27 0000      read      Outside temperature   0.00 deg C
Boiler:         6  27 0000      Data Ivld Outside temperature   0.00 deg C
Controller:     0  33 0000      read      Exhaust temperature  0 deg C
Boiler:         4  33 002f      read ACK  Exhaust temperature  47 deg C
Controller:     0 116 0000      read      Burner starts  0 
Boiler:         7 116 0000      Unk DatID Burner starts  0 
Controller:     0 119 0000      read      DHW burner starts  0 
Boiler:         7 119 0000      Unk DatID DHW burner starts  0 
Controller:     0 120 0000      read      Burner operation hours  0 hrs
Boiler:         7 120 0000      Unk DatID Burner operation hours  0 hrs
Controller:     0 123 0000      read      DHW burner operation hours  0 hrs
Boiler:         7 123 0000      Unk DatID DHW burner operation hours  0 hrs
Controller:     0  36 0000      read      Electrical current through burner flame   0.00 uA
Boiler:         7  36 0000      Unk DatID Electrical current through burner flame   0.00 uA
Controller:     0  57 5200      read      Max CH water setpoint  82.00 deg C
Boiler:         4  57 5200      read ACK  Max CH water setpoint  82.00 deg C

# front panel started showing error 738 (OpenTherm remote control connected but not configured)

Controller:     0 115 0000      read      OEM-specific diagnostic/service code  0 
Boiler:         4 115 02e2      read ACK  OEM-specific diagnostic/service code  738 
Controller:     0  19 0000      read      DHW flow rate   0.00 l/min
Boiler:         6  19 0000      Data Ivld DHW flow rate   0.00 l/min
Controller:     0   0 0200      read      Master and Slave status  00000010, 00000000 
Boiler:         4   0 020b      read ACK  Master and Slave status  00000010, 00001011 
Controller:     0   0 0200      read      Master and Slave status  00000010, 00000000 
Boiler:         4   0 020b      read ACK  Master and Slave status  00000010, 00001011 
Controller:     0   0 0200      read      Master and Slave status  00000010, 00000000 
Boiler:         4   0 020b      read ACK  Master and Slave status  00000010, 00001011 
Controller:     0  26 5200      read      DHW temperature  82.00 deg C
Boiler:         6  26 0000      Data Ivld DHW temperature   0.00 deg C
Controller:     0  25 5200      read      Boiler water temperature  82.00 deg C
Boiler:         4  25 3899      read ACK  Boiler water temperature  56.60 deg C
Controller:     0  17 0000      read      Relative Modulation Level   0.00 %
Boiler:         4  17 2700      read ACK  Relative Modulation Level  39.00 %
Controller:     1  16 1400      write     Room Setpoint  20.00 deg C
Boiler:         7  16 0000      Unk DatID Room Setpoint   0.00 deg C
Controller:     1  24 1bb5      write     Room Temperature  27.71 deg C
Boiler:         7  24 0000      Unk DatID Room Temperature   0.00 deg C
Controller:     1   1 0000      write     Control setpoint   0.00 deg C
Boiler:         5   1 3c00      write ACK Control setpoint  60.00 deg C
Controller:     1  14 6400      write     Maximum relative modulation level setting  100.00 %
Boiler:         5  14 6400      write ACK Maximum relative modulation level setting  100.00 %
Controller:     0   5 0000      read      Application-specific fault  00000000, 0 
Boiler:         4   5 01ff      read ACK  Application-specific fault  00000001, 255 
Controller:     0  28 5200      read      Return water temperature  82.00 deg C
Boiler:         7  28 0000      Unk DatID Return water temperature   0.00 deg C
Controller:     0  18 0000      read      CH water pressure   0.00 bar
Boiler:         4  18 0133      read ACK  CH water pressure   1.20 bar
Controller:     0  27 5200      read      Outside temperature  82.00 deg C
Boiler:         6  27 0000      Data Ivld Outside temperature   0.00 deg C
Controller:     0  33 5200      read      Exhaust temperature  20992 deg C
Boiler:         4  33 0034      read ACK  Exhaust temperature  52 deg C
Controller:     0 116 0000      read      Burner starts  0 
Boiler:         7 116 0000      Unk DatID Burner starts  0 
Controller:     0 119 0000      read      DHW burner starts  0 
Boiler:         7 119 0000      Unk DatID DHW burner starts  0 
Controller:     0 120 0000      read      Burner operation hours  0 hrs
Boiler:         7 120 0000      Unk DatID Burner operation hours  0 hrs
Controller:     0 123 0000      read      DHW burner operation hours  0 hrs
Boiler:         7 123 0000      Unk DatID DHW burner operation hours  0 hrs
Controller:     0  36 0000      read      Electrical current through burner flame   0.00 uA
Boiler:         7  36 0000      Unk DatID Electrical current through burner flame   0.00 uA
Controller:     0  57 5200      read      Max CH water setpoint  82.00 deg C
Boiler:         4  57 5200      read ACK  Max CH water setpoint  82.00 deg C

[repeats several times...]

# At this point I configured the Viessmann into OpenTherm mode and cleared the error display

Controller:     0 115 0000      read      OEM-specific diagnostic/service code  0 
Boiler:         4 115 0000      read ACK  OEM-specific diagnostic/service code  0 
Controller:     0  19 0000      read      DHW flow rate   0.00 l/min
Boiler:         6  19 0000      Data Ivld DHW flow rate   0.00 l/min
Controller:     0   0 0200      read      Master and Slave status  00000010, 00000000   # Master status: CH disabled, DHW enabled 
Boiler:         4   0 0200      read ACK  Master and Slave status  00000010, 00000000   # Slave status: no fault, CH not active, DHW not active, flame off
Controller:     0   0 0200      read      Master and Slave status  00000010, 00000000 
Boiler:         4   0 0200      read ACK  Master and Slave status  00000010, 00000000 
Controller:     0   0 0200      read      Master and Slave status  00000010, 00000000 
Boiler:         4   0 0200      read ACK  Master and Slave status  00000010, 00000000 
Controller:     0  26 5200      read      DHW temperature  82.00 deg C
Boiler:         6  26 0000      Data Ivld DHW temperature   0.00 deg C
Controller:     0  25 5200      read      Boiler water temperature  82.00 deg C
Boiler:         4  25 2eb3      read ACK  Boiler water temperature  46.70 deg C
Controller:     0  17 0000      read      Relative Modulation Level   0.00 %
Boiler:         4  17 0000      read ACK  Relative Modulation Level   0.00 %
Controller:     1  16 1400      write     Room Setpoint  20.00 deg C
Boiler:         7  16 0000      Unk DatID Room Setpoint   0.00 deg C    # unrecognised command
Controller:     1  24 1bb5      write     Room Temperature  27.71 deg C
Boiler:         7  24 0000      Unk DatID Room Temperature   0.00 deg C # unrecognised command
Controller:     1   1 0000      write     Control setpoint   0.00 deg C
Boiler:         5   1 1400      write ACK Control setpoint  20.00 deg C
Controller:     1  14 6400      write     Maximum relative modulation level setting  100.00 %
Boiler:         5  14 6400      write ACK Maximum relative modulation level setting  100.00 %
Controller:     0   5 0000      read      Application-specific fault  00000000, 0 
Boiler:         4   5 00ff      read ACK  Application-specific fault  00000000, 255 # the 'service required' flag has now cleared 
Controller:     0  28 5200      read      Return water temperature  82.00 deg C
Boiler:         7  28 0000      Unk DatID Return water temperature   0.00 deg C
Controller:     0  18 0000      read      CH water pressure   0.00 bar
Boiler:         4  18 0133      read ACK  CH water pressure   1.20 bar
Controller:     0  27 5200      read      Outside temperature  82.00 deg C  # Slave was saving the new configuration and rebooting
Controller:     0  27 5200      read      Outside temperature  82.00 deg C
Controller:     0  27 5200      read      Outside temperature  82.00 deg C
Controller:     0  27 5200      read      Outside temperature  82.00 deg C
Controller:     0  27 5200      read      Outside temperature  82.00 deg C
Controller:     0  27 5200      read      Outside temperature  82.00 deg C
Boiler:         6  27 0000      Data Ivld Outside temperature   0.00 deg C
Controller:     0  33 5200      read      Exhaust temperature  20992 deg C
Boiler:         6  33 0000      Data Ivld Exhaust temperature  0 deg C  # Slave doesn't have any valid data at this point (rebooting)
Controller:     0 116 0000      read      Burner starts  0 
Boiler:         7 116 0000      Unk DatID Burner starts  0 
Controller:     0 119 0000      read      DHW burner starts  0 
Boiler:         7 119 0000      Unk DatID DHW burner starts  0 
Controller:     0 120 0000      read      Burner operation hours  0 hrs
Boiler:         7 120 0000      Unk DatID Burner operation hours  0 hrs
Controller:     0 123 0000      read      DHW burner operation hours  0 hrs
Boiler:         7 123 0000      Unk DatID DHW burner operation hours  0 hrs
Controller:     0  36 0000      read      Electrical current through burner flame   0.00 uA
Boiler:         7  36 0000      Unk DatID Electrical current through burner flame   0.00 uA
Controller:     0  57 5200      read      Max CH water setpoint  82.00 deg C
Boiler:         4  57 5200      read ACK  Max CH water setpoint  82.00 deg C

[Repeats...]

Boiler:         4  25 2b80      read ACK  Boiler water temperature  43.50 deg C
Boiler:         4  18 0119      read ACK  CH water pressure   1.10 bar
Boiler:         4  33 002d      read ACK  Exhaust temperature  45 deg C

Boiler:         4  25 2ae6      read ACK  Boiler water temperature  42.90 deg C
Boiler:         4  18 0119      read ACK  CH water pressure   1.10 bar
Boiler:         4  33 002c      read ACK  Exhaust temperature  44 deg C

Boiler:         4  25 2b00      read ACK  Boiler water temperature  43.00 deg C
Boiler:         4  18 0119      read ACK  CH water pressure   1.10 bar
Boiler:         4  33 002c      read ACK  Exhaust temperature  44 deg C

Boiler:         4  25 2b00      read ACK  Boiler water temperature  43.00 deg C
Boiler:         4  18 0119      read ACK  CH water pressure   1.10 bar
Boiler:         4  33 002c      read ACK  Exhaust temperature  44 deg C

Boiler:         4  25 2b33      read ACK  Boiler water temperature  43.20 deg C
Boiler:         4  18 0119      read ACK  CH water pressure   1.10 bar
Boiler:         4  33 002c      read ACK  Exhaust temperature  44 deg C

Boiler:         4  25 2b4d      read ACK  Boiler water temperature  43.30 deg C
Boiler:         4  18 0119      read ACK  CH water pressure   1.10 bar
Boiler:         4  33 002c      read ACK  Exhaust temperature  44 deg C

Boiler:         4  25 2b4d      read ACK  Boiler water temperature  43.30 deg C
Boiler:         4  18 0119      read ACK  CH water pressure   1.10 bar
Boiler:         4  33 002c      read ACK  Exhaust temperature  44 deg C

Boiler:         4  25 2b66      read ACK  Boiler water temperature  43.40 deg C
Boiler:         4  18 0119      read ACK  CH water pressure   1.10 bar
Boiler:         4  33 002c      read ACK  Exhaust temperature  44 deg C

Boiler:         4  25 2b66      read ACK  Boiler water temperature  43.40 deg C
Boiler:         4  18 0119      read ACK  CH water pressure   1.10 bar
Boiler:         4  33 002b      read ACK  Exhaust temperature  43 deg C

# at this point I put the Tado into CH Boost mode
# then after a while realised I had to manually open the CH zone valve

Controller:     0   0 0300      read      Master and Slave status  00000011, 00000000   # Master status: CH enabled, DHW enabled
Boiler:         4   0 0300      read ACK  Master and Slave status  00000011, 00000000 
Controller:     0   0 0300      read      Master and Slave status  00000011, 00000000 
Boiler:         4   0 0302      read ACK  Master and Slave status  00000011, 00000010   # Slave status: no fault, CH active, DHW not active
Controller:     0   0 0300      read      Master and Slave status  00000011, 00000000 
Boiler:         4   0 0302      read ACK  Master and Slave status  00000011, 00000010 
Controller:     0   0 0300      read      Master and Slave status  00000011, 00000000 
Boiler:         4   0 0302      read ACK  Master and Slave status  00000011, 00000010 
Controller:     0   0 0300      read      Master and Slave status  00000011, 00000000 
Boiler:         4   0 0302      read ACK  Master and Slave status  00000011, 00000010 
Controller:     0   0 0300      read      Master and Slave status  00000011, 00000000 
Boiler:         4   0 0302      read ACK  Master and Slave status  00000011, 00000010 


Boiler:         4  25 2be6      read ACK  Boiler water temperature  43.90 deg C

Controller:     0  17 0000      read      Relative Modulation Level   0.00 %
Boiler:         4  17 0000      read ACK  Relative Modulation Level   0.00 %
Controller:     1  16 1e00      write     Room Setpoint  30.00 deg C    # the Tado increases the room setpoint
Boiler:         7  16 0000      Unk DatID Room Setpoint   0.00 deg C

Boiler:         4  18 0133      read ACK  CH water pressure   1.20 bar
Boiler:         4  33 002b      read ACK  Exhaust temperature  43 deg C # the boiler hasn't yet started

Boiler:         4  25 2d4d      read ACK  Boiler water temperature  45.30 deg C
Boiler:         4  18 0133      read ACK  CH water pressure   1.20 bar
Boiler:         4  33 002c      read ACK  Exhaust temperature  44 deg C

Controller:     0   0 0300      read      Master and Slave status  00000011, 00000000 
Boiler:         4   0 0302      read ACK  Master and Slave status  00000011, 00000010 
Controller:     0   0 0300      read      Master and Slave status  00000011, 00000000 
Boiler:         4   0 0302      read ACK  Master and Slave status  00000011, 00000010 
Controller:     0   0 0300      read      Master and Slave status  00000011, 00000000 
Boiler:         4   0 0302      read ACK  Master and Slave status  00000011, 00000010 

Boiler:         4  25 3019      read ACK  Boiler water temperature  48.10 deg C     # Temperature is increasing (but flame is "off")
Controller:     0  17 0000      read      Relative Modulation Level   0.00 %
Boiler:         4  17 0000      read ACK  Relative Modulation Level   0.00 %        # boiler is not reporting any modulation

Controller:     1   1 3000      write     Control setpoint  48.00 deg C
Boiler:         5   1 3000      write ACK Control setpoint  48.00 deg C     # master is increasing the control setpoint

Boiler:         4  25 3299      read ACK  Boiler water temperature  50.60 deg C

Controller:     1   1 3200      write     Control setpoint  50.00 deg C
Boiler:         5   1 3200      write ACK Control setpoint  50.00 deg C     # master continues to increase the control setpoint

Boiler:         4  18 0133      read ACK  CH water pressure   1.20 bar
Boiler:         4  33 002d      read ACK  Exhaust temperature  45 deg C

Controller:     0   0 0300      read      Master and Slave status  00000011, 00000000 
Boiler:         4   0 0302      read ACK  Master and Slave status  00000011, 00000010   # boiler is still reporting 'flame off'
Controller:     0   0 0300      read      Master and Slave status  00000011, 00000000 
Boiler:         4   0 0302      read ACK  Master and Slave status  00000011, 00000010 
Controller:     0   0 0300      read      Master and Slave status  00000011, 00000000 
Boiler:         4   0 0302      read ACK  Master and Slave status  00000011, 00000010 

Boiler:         4  25 3433      read ACK  Boiler water temperature  52.20 deg C

Controller:     1   1 3400      write     Control setpoint  52.00 deg C
Boiler:         5   1 3400      write ACK Control setpoint  52.00 deg C

Boiler:         4  18 0133      read ACK  CH water pressure   1.20 bar
Boiler:         4  33 002d      read ACK  Exhaust temperature  45 deg C

Boiler:         4  25 3433      read ACK  Boiler water temperature  52.20 deg C

Controller:     1   1 5200      write     Control setpoint  82.00 deg C     # master now sets the maximum control setpoint
Boiler:         5   1 5200      write ACK Control setpoint  82.00 deg C

Boiler:         4  18 0133      read ACK  CH water pressure   1.20 bar
Boiler:         4  33 002e      read ACK  Exhaust temperature  46 deg C

Controller:     0   0 0300      read      Master and Slave status  00000011, 00000000 
Boiler:         4   0 0302      read ACK  Master and Slave status  00000011, 00000010 
Controller:     0   0 0300      read      Master and Slave status  00000011, 00000000 
Boiler:         4   0 0302      read ACK  Master and Slave status  00000011, 00000010 
Controller:     0   0 0300      read      Master and Slave status  00000011, 00000000 
Boiler:         4   0 0302      read ACK  Master and Slave status  00000011, 00000010 

Boiler:         4  25 3200      read ACK  Boiler water temperature  50.00 deg C

Controller:     1   1 5200      write     Control setpoint  82.00 deg C
Boiler:         5   1 5200      write ACK Control setpoint  82.00 deg C

Boiler:         4  18 0133      read ACK  CH water pressure   1.20 bar
Boiler:         4  33 002e      read ACK  Exhaust temperature  46 deg C

Boiler:         4  25 30b3      read ACK  Boiler water temperature  48.70 deg C
Boiler:         4  18 0133      read ACK  CH water pressure   1.20 bar
Boiler:         4  33 002e      read ACK  Exhaust temperature  46 deg C

Boiler:         4  25 2dcd      read ACK  Boiler water temperature  45.80 deg C
Boiler:         4  18 0133      read ACK  CH water pressure   1.20 bar
Boiler:         4  33 002d      read ACK  Exhaust temperature  45 deg C

Boiler:         4  25 31b3      read ACK  Boiler water temperature  49.70 deg C
Boiler:         4  17 2700      read ACK  Relative Modulation Level  39.00 %    # boiler now reports some modulation
Boiler:         4  33 0031      read ACK  Exhaust temperature  49 deg C

Boiler:         4  25 374d      read ACK  Boiler water temperature  55.30 deg C
Boiler:         4  17 2700      read ACK  Relative Modulation Level  39.00 %

Boiler:         4  18 0133      read ACK  CH water pressure   1.20 bar
Boiler:         4  33 002d      read ACK  Exhaust temperature  45 deg C

Controller:     0   0 0300      read      Master and Slave status  00000011, 00000000 
Boiler:         4   0 030a      read ACK  Master and Slave status  00000011, 00001010   # slave status now reports flame on
Controller:     0   0 0300      read      Master and Slave status  00000011, 00000000 
Boiler:         4   0 030a      read ACK  Master and Slave status  00000011, 00001010 
Controller:     0   0 0300      read      Master and Slave status  00000011, 00000000 
Boiler:         4   0 030a      read ACK  Master and Slave status  00000011, 00001010 

Boiler:         4  25 3119      read ACK  Boiler water temperature  49.10 deg C
Boiler:         4  17 2600      read ACK  Relative Modulation Level  38.00 %

Boiler:         4  18 0133      read ACK  CH water pressure   1.20 bar
Boiler:         4  33 002b      read ACK  Exhaust temperature  43 deg C

Boiler:         4  25 2f00      read ACK  Boiler water temperature  47.00 deg C
Boiler:         4  17 2600      read ACK  Relative Modulation Level  38.00 %
Boiler:         4  18 0133      read ACK  CH water pressure   1.20 bar
Boiler:         4  33 002a      read ACK  Exhaust temperature  42 deg C

Boiler:         4  25 2e80      read ACK  Boiler water temperature  46.50 deg C
Boiler:         4  17 3200      read ACK  Relative Modulation Level  50.00 %
Boiler:         4  18 0133      read ACK  CH water pressure   1.20 bar
Boiler:         4  33 0029      read ACK  Exhaust temperature  41 deg C

Boiler:         4  25 3033      read ACK  Boiler water temperature  48.20 deg C
Boiler:         4  17 3a00      read ACK  Relative Modulation Level  58.00 %
Boiler:         4  18 0133      read ACK  CH water pressure   1.20 bar
Boiler:         4  33 002b      read ACK  Exhaust temperature  43 deg C

Boiler:         4  25 32e6      read ACK  Boiler water temperature  50.90 deg C
Boiler:         4  17 3f00      read ACK  Relative Modulation Level  63.00 %
Boiler:         4  18 0133      read ACK  CH water pressure   1.20 bar
Boiler:         4  33 002d      read ACK  Exhaust temperature  45 deg C

Boiler:         4  25 34b3      read ACK  Boiler water temperature  52.70 deg C
Boiler:         4  17 4300      read ACK  Relative Modulation Level  67.00 %
Boiler:         4  18 0133      read ACK  CH water pressure   1.20 bar
Boiler:         4  33 002e      read ACK  Exhaust temperature  46 deg C

Boiler:         4  25 354d      read ACK  Boiler water temperature  53.30 deg C
Boiler:         4  17 4a00      read ACK  Relative Modulation Level  74.00 %
Boiler:         4  18 0133      read ACK  CH water pressure   1.20 bar
Boiler:         4  33 002e      read ACK  Exhaust temperature  46 deg C

Boiler:         4  25 3666      read ACK  Boiler water temperature  54.40 deg C
Boiler:         4  17 5100      read ACK  Relative Modulation Level  81.00 %
Boiler:         4  18 0133      read ACK  CH water pressure   1.20 bar
Boiler:         4  33 002e      read ACK  Exhaust temperature  46 deg C

Boiler:         4  25 3766      read ACK  Boiler water temperature  55.40 deg C
Boiler:         4  17 5600      read ACK  Relative Modulation Level  86.00 %
Boiler:         4  18 0133      read ACK  CH water pressure   1.20 bar
Boiler:         4  33 002f      read ACK  Exhaust temperature  47 deg C

Boiler:         4  25 38b3      read ACK  Boiler water temperature  56.70 deg C
Boiler:         4  18 0133      read ACK  CH water pressure   1.20 bar
Boiler:         4  33 0031      read ACK  Exhaust temperature  49 deg C

Boiler:         4  25 3a4d      read ACK  Boiler water temperature  58.30 deg C
Boiler:         4  17 5f00      read ACK  Relative Modulation Level  95.00 %
Boiler:         4  18 0133      read ACK  CH water pressure   1.20 bar
Boiler:         4  33 0032      read ACK  Exhaust temperature  50 deg C

Boiler:         4  25 3bcd      read ACK  Boiler water temperature  59.80 deg C
Boiler:         4  17 6300      read ACK  Relative Modulation Level  99.00 %    # boiler is now running at more-or-less full power
Boiler:         4  18 0133      read ACK  CH water pressure   1.20 bar

Boiler:         4  25 3e19      read ACK  Boiler water temperature  62.10 deg C
Boiler:         4  17 6300      read ACK  Relative Modulation Level  99.00 %
Boiler:         4  18 0133      read ACK  CH water pressure   1.20 bar
Boiler:         4  33 0037      read ACK  Exhaust temperature  55 deg C

Boiler:         4  25 3f80      read ACK  Boiler water temperature  63.50 deg C
Boiler:         4  17 6300      read ACK  Relative Modulation Level  99.00 %
Boiler:         4  18 0133      read ACK  CH water pressure   1.20 bar
Boiler:         4  33 0039      read ACK  Exhaust temperature  57 deg C

# At this point I cancelled the CH boost on the Tado

Controller:     0   0 0200      read      Master and Slave status  00000010, 00000000   # Master: CH not enabled, DHW enabled 
Boiler:         4   0 020a      read ACK  Master and Slave status  00000010, 00001010   # Slave: CH active, flame on
Controller:     0   0 0200      read      Master and Slave status  00000010, 00000000 
Boiler:         4   0 0208      read ACK  Master and Slave status  00000010, 00001000 
Controller:     0   0 0200      read      Master and Slave status  00000010, 00000000
Boiler:         4   0 0208      read ACK  Master and Slave status  00000010, 00001000   # Slave: CH not active, flame still on
Controller:     0   0 0200      read      Master and Slave status  00000010, 00000000 
Boiler:         4   0 0208      read ACK  Master and Slave status  00000010, 00001000 
Controller:     0   0 0200      read      Master and Slave status  00000010, 00000000 
Boiler:         4   0 0208      read ACK  Master and Slave status  00000010, 00001000 
Controller:     0   0 0200      read      Master and Slave status  00000010, 00000000 
Boiler:         4   0 0200      read ACK  Master and Slave status  00000010, 00000000  # Slave: flame now off 
Controller:     0   0 0200      read      Master and Slave status  00000010, 00000000 
Boiler:         4   0 0200      read ACK  Master and Slave status  00000010, 00000000 
Controller:     0   0 0200      read      Master and Slave status  00000010, 00000000 
Boiler:         4   0 0200      read ACK  Master and Slave status  00000010, 00000000 
Controller:     0   0 0200      read      Master and Slave status  00000010, 00000000 
Boiler:         4   0 0200      read ACK  Master and Slave status  00000010, 00000000 

Boiler:         4  25 3e00      read ACK  Boiler water temperature  62.00 deg C
Boiler:         4  17 0000      read ACK  Relative Modulation Level   0.00 %            # boiler has modulated off

Controller:     1   1 0000      write     Control setpoint   0.00 deg C
Boiler:         5   1 1400      write ACK Control setpoint  20.00 deg C                 # Master sets minimum control setpoint
Controller:     1  14 6400      write     Maximum relative modulation level setting  100.00 %
Boiler:         5  14 6400      write ACK Maximum relative modulation level setting  100.00 %

Boiler:         4  18 0133      read ACK  CH water pressure   1.20 bar
Boiler:         4  33 0035      read ACK  Exhaust temperature  53 deg C

Boiler:         4  25 2ee6      read ACK  Boiler water temperature  46.90 deg           # boiler starts to cool down
Boiler:         4  18 0133      read ACK  CH water pressure   1.20 bar
Boiler:         4  33 0030      read ACK  Exhaust temperature  48 deg C

Boiler:         4  25 2b4d      read ACK  Boiler water temperature  43.30 deg C
Boiler:         4  18 0133      read ACK  CH water pressure   1.20 bar
Boiler:         4  33 002d      read ACK  Exhaust temperature  45 deg C

Boiler:         4  25 2ae6      read ACK  Boiler water temperature  42.90 deg C
Boiler:         4  18 0133      read ACK  CH water pressure   1.20 bar
Boiler:         4  33 002c      read ACK  Exhaust temperature  44 deg C

Boiler:         4  25 2b00      read ACK  Boiler water temperature  43.00 deg C
Boiler:         4  18 0133      read ACK  CH water pressure   1.20 bar
Boiler:         4  33 002c      read ACK  Exhaust temperature  44 deg C

Boiler:         4  25 2b33      read ACK  Boiler water temperature  43.20 deg C
Boiler:         4  18 0133      read ACK  CH water pressure   1.20 bar
Boiler:         4  33 002b      read ACK  Exhaust temperature  43 deg C

[etc...]
---- Closed the serial port COM3 ----
