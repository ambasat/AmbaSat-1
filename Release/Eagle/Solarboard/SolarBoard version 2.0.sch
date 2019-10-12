<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="7.6.0">
<drawing>
<settings>
<setting alwaysvectorfont="no"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.1" unitdist="inch" unit="inch" style="lines" multiple="1" display="no" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="1" name="Top" color="4" fill="1" visible="no" active="no"/>
<layer number="2" name="Route2" color="1" fill="3" visible="no" active="no"/>
<layer number="3" name="Route3" color="4" fill="3" visible="no" active="no"/>
<layer number="4" name="Route4" color="1" fill="4" visible="no" active="no"/>
<layer number="5" name="Route5" color="4" fill="4" visible="no" active="no"/>
<layer number="6" name="Route6" color="1" fill="8" visible="no" active="no"/>
<layer number="7" name="Route7" color="4" fill="8" visible="no" active="no"/>
<layer number="8" name="Route8" color="1" fill="2" visible="no" active="no"/>
<layer number="9" name="Route9" color="4" fill="2" visible="no" active="no"/>
<layer number="10" name="Route10" color="1" fill="7" visible="no" active="no"/>
<layer number="11" name="Route11" color="4" fill="7" visible="no" active="no"/>
<layer number="12" name="Route12" color="1" fill="5" visible="no" active="no"/>
<layer number="13" name="Route13" color="4" fill="5" visible="no" active="no"/>
<layer number="14" name="Route14" color="1" fill="6" visible="no" active="no"/>
<layer number="15" name="Route15" color="4" fill="6" visible="no" active="no"/>
<layer number="16" name="Bottom" color="1" fill="1" visible="no" active="no"/>
<layer number="17" name="Pads" color="2" fill="1" visible="no" active="no"/>
<layer number="18" name="Vias" color="2" fill="1" visible="no" active="no"/>
<layer number="19" name="Unrouted" color="6" fill="1" visible="no" active="no"/>
<layer number="20" name="Dimension" color="15" fill="1" visible="no" active="no"/>
<layer number="21" name="tPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="22" name="bPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="23" name="tOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="24" name="bOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="25" name="tNames" color="7" fill="1" visible="no" active="no"/>
<layer number="26" name="bNames" color="7" fill="1" visible="no" active="no"/>
<layer number="27" name="tValues" color="7" fill="1" visible="no" active="no"/>
<layer number="28" name="bValues" color="7" fill="1" visible="no" active="no"/>
<layer number="29" name="tStop" color="7" fill="3" visible="no" active="no"/>
<layer number="30" name="bStop" color="7" fill="6" visible="no" active="no"/>
<layer number="31" name="tCream" color="7" fill="4" visible="no" active="no"/>
<layer number="32" name="bCream" color="7" fill="5" visible="no" active="no"/>
<layer number="33" name="tFinish" color="6" fill="3" visible="no" active="no"/>
<layer number="34" name="bFinish" color="6" fill="6" visible="no" active="no"/>
<layer number="35" name="tGlue" color="7" fill="4" visible="no" active="no"/>
<layer number="36" name="bGlue" color="7" fill="5" visible="no" active="no"/>
<layer number="37" name="tTest" color="7" fill="1" visible="no" active="no"/>
<layer number="38" name="bTest" color="7" fill="1" visible="no" active="no"/>
<layer number="39" name="tKeepout" color="4" fill="11" visible="no" active="no"/>
<layer number="40" name="bKeepout" color="1" fill="11" visible="no" active="no"/>
<layer number="41" name="tRestrict" color="4" fill="10" visible="no" active="no"/>
<layer number="42" name="bRestrict" color="1" fill="10" visible="no" active="no"/>
<layer number="43" name="vRestrict" color="2" fill="10" visible="no" active="no"/>
<layer number="44" name="Drills" color="7" fill="1" visible="no" active="no"/>
<layer number="45" name="Holes" color="7" fill="1" visible="no" active="no"/>
<layer number="46" name="Milling" color="3" fill="1" visible="no" active="no"/>
<layer number="47" name="Measures" color="7" fill="1" visible="no" active="no"/>
<layer number="48" name="Document" color="7" fill="1" visible="no" active="no"/>
<layer number="49" name="Reference" color="7" fill="1" visible="no" active="no"/>
<layer number="50" name="dxf" color="7" fill="1" visible="no" active="no"/>
<layer number="51" name="tDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="52" name="bDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="90" name="Modules" color="5" fill="1" visible="yes" active="yes"/>
<layer number="91" name="Nets" color="2" fill="1" visible="yes" active="yes"/>
<layer number="92" name="Busses" color="1" fill="1" visible="yes" active="yes"/>
<layer number="93" name="Pins" color="2" fill="1" visible="no" active="yes"/>
<layer number="94" name="Symbols" color="4" fill="1" visible="yes" active="yes"/>
<layer number="95" name="Names" color="7" fill="1" visible="yes" active="yes"/>
<layer number="96" name="Values" color="7" fill="1" visible="yes" active="yes"/>
<layer number="97" name="Info" color="7" fill="1" visible="yes" active="yes"/>
<layer number="98" name="Guide" color="6" fill="1" visible="yes" active="yes"/>
<layer number="250" name="Descript" color="3" fill="1" visible="no" active="no"/>
<layer number="251" name="SMDround" color="12" fill="11" visible="no" active="no"/>
</layers>
<schematic xreflabel="%F%N/%S.%C%R" xrefpart="/%S.%C%R">
<libraries>
<library name="trisolx-ks">
<packages>
<package name="SOLAR_WINGS">
<wire x1="-26.3" y1="0" x2="0" y2="0" width="0.127" layer="21"/>
<wire x1="0" y1="0" x2="0" y2="8" width="0.127" layer="21"/>
<wire x1="0" y1="8" x2="-14.3" y2="8" width="0.127" layer="21"/>
<wire x1="-14.3" y1="8" x2="-16.75" y2="8" width="0.127" layer="21"/>
<wire x1="-16.75" y1="8" x2="-21.75" y2="5.5" width="0.127" layer="21"/>
<wire x1="-21.75" y1="5.5" x2="-26.3" y2="0" width="0.127" layer="21"/>
<wire x1="-26.3" y1="0" x2="-14.3" y2="8" width="0.127" layer="21" curve="-37.677485"/>
<pad name="NEG" x="1.2" y="1.5" drill="0.6" rot="R90"/>
<wire x1="-26.6" y1="-0.2" x2="0.2" y2="-0.2" width="0.0508" layer="39"/>
<wire x1="0.2" y1="-0.2" x2="0.2" y2="0.8" width="0.0508" layer="39"/>
<wire x1="0.2" y1="0.8" x2="1.265" y2="0.8" width="0.0508" layer="39"/>
<wire x1="1.265" y1="0.8" x2="1.9" y2="1.435" width="0.0508" layer="39" curve="90"/>
<wire x1="1.9" y1="1.435" x2="1.9" y2="1.565" width="0.0508" layer="39"/>
<wire x1="1.9" y1="1.565" x2="1.265" y2="2.2" width="0.0508" layer="39" curve="90"/>
<wire x1="1.265" y1="2.2" x2="0.2" y2="2.2" width="0.0508" layer="39"/>
<wire x1="0.2" y1="2.2" x2="0.2" y2="8.2" width="0.0508" layer="39"/>
<wire x1="0.2" y1="8.2" x2="-16.8" y2="8.2" width="0.0508" layer="39"/>
<wire x1="-16.8" y1="8.2" x2="-22" y2="5.6" width="0.0508" layer="39"/>
<wire x1="-22" y1="5.6" x2="-26.6" y2="0" width="0.0508" layer="39"/>
<wire x1="-26.6" y1="0" x2="-26.6" y2="-0.2" width="0.0508" layer="39"/>
<text x="-25.4" y="-1.27" size="0.6096" layer="25">&gt;NAME</text>
<text x="-11.43" y="-1.27" size="0.6096" layer="27">&gt;VALUE</text>
<smd name="POS" x="-11.1" y="3.8" dx="20" dy="2" layer="1" roundness="100"/>
</package>
<package name="SOLAR_WINGS_SMD">
<wire x1="-26.3" y1="0" x2="0" y2="0" width="0.127" layer="21"/>
<wire x1="0" y1="0" x2="0" y2="8" width="0.127" layer="21"/>
<wire x1="0" y1="8" x2="-14.3" y2="8" width="0.127" layer="21"/>
<wire x1="-14.3" y1="8" x2="-16.75" y2="8" width="0.127" layer="21"/>
<wire x1="-16.75" y1="8" x2="-21.75" y2="5.5" width="0.127" layer="21"/>
<wire x1="-21.75" y1="5.5" x2="-26.3" y2="0" width="0.127" layer="21"/>
<wire x1="-26.6" y1="-0.2" x2="1.1" y2="-0.2" width="0.0508" layer="39"/>
<wire x1="1.1" y1="-0.2" x2="1.1" y2="8.2" width="0.0508" layer="39"/>
<wire x1="1.1" y1="8.2" x2="-16.8" y2="8.2" width="0.0508" layer="39"/>
<wire x1="-16.8" y1="8.2" x2="-22" y2="5.6" width="0.0508" layer="39"/>
<wire x1="-22" y1="5.6" x2="-26.6" y2="0" width="0.0508" layer="39"/>
<wire x1="-26.6" y1="0" x2="-26.6" y2="-0.2" width="0.0508" layer="39"/>
<smd name="POS" x="-11.1" y="3.8" dx="20" dy="2" layer="1" roundness="100"/>
<text x="-25.4" y="-1.27" size="0.6096" layer="25">&gt;NAME</text>
<text x="-11.43" y="-1.27" size="0.6096" layer="27">&gt;VALUE</text>
<smd name="NEG" x="0.6" y="4" dx="6" dy="0.5" layer="1" roundness="100" rot="R90"/>
</package>
</packages>
<symbols>
<symbol name="SOLAR">
<wire x1="-1.905" y1="0.635" x2="-1.905" y2="0" width="0.4064" layer="94"/>
<wire x1="-1.905" y1="0" x2="-1.905" y2="-0.635" width="0.4064" layer="94"/>
<wire x1="-0.635" y1="2.54" x2="-0.635" y2="-2.54" width="0.4064" layer="94"/>
<wire x1="-5.08" y1="0" x2="-1.905" y2="0" width="0.1524" layer="94"/>
<wire x1="-0.508" y1="0" x2="2.667" y2="0" width="0.1524" layer="94"/>
<wire x1="-5.588" y1="4.318" x2="-4.191" y2="2.921" width="0.1524" layer="94"/>
<wire x1="-5.715" y1="3.175" x2="-4.318" y2="1.778" width="0.1524" layer="94"/>
<text x="-2.54" y="3.175" size="1.778" layer="95">&gt;NAME</text>
<text x="-2.54" y="-5.08" size="1.778" layer="96">&gt;VALUE</text>
<pin name="NEG" x="-7.62" y="0" visible="pad" length="short"/>
<pin name="POS" x="5.08" y="0" visible="pad" length="short" rot="R180"/>
<polygon width="0.1524" layer="94">
<vertex x="-4.191" y="2.921"/>
<vertex x="-4.572" y="3.81"/>
<vertex x="-5.08" y="3.302"/>
</polygon>
<polygon width="0.1524" layer="94">
<vertex x="-4.318" y="1.778"/>
<vertex x="-4.699" y="2.667"/>
<vertex x="-5.207" y="2.159"/>
</polygon>
</symbol>
</symbols>
<devicesets>
<deviceset name="SOLAR_WINGS" prefix="S">
<description>1 Sun: AM 1.5G -(100 mW/cm2) @ 25ᵒC, Voltage (Open Circuit): 2.62 V, Voltage (Max Power):2.33 V, Current (Max Power):14.6 mA, Power (Max Power): 34 mW, Efficiency: 28%, Temp Coeff. V (Max Power): -6.1 mV/ᵒC</description>
<gates>
<gate name="G$1" symbol="SOLAR" x="0" y="0"/>
</gates>
<devices>
<device name="" package="SOLAR_WINGS">
<connects>
<connect gate="G$1" pin="NEG" pad="NEG"/>
<connect gate="G$1" pin="POS" pad="POS"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="SMD" package="SOLAR_WINGS_SMD">
<connects>
<connect gate="G$1" pin="NEG" pad="NEG"/>
<connect gate="G$1" pin="POS" pad="POS"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="pinhead">
<description>&lt;b&gt;Pin Header Connectors&lt;/b&gt;&lt;p&gt;
&lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
<package name="1X02">
<description>&lt;b&gt;PIN HEADER&lt;/b&gt;</description>
<wire x1="-1.905" y1="1.27" x2="-0.635" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-0.635" y1="1.27" x2="0" y2="0.635" width="0.1524" layer="21"/>
<wire x1="0" y1="0.635" x2="0" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="0" y1="-0.635" x2="-0.635" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-2.54" y1="0.635" x2="-2.54" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="-1.905" y1="1.27" x2="-2.54" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-2.54" y1="-0.635" x2="-1.905" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-0.635" y1="-1.27" x2="-1.905" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="0" y1="0.635" x2="0.635" y2="1.27" width="0.1524" layer="21"/>
<wire x1="0.635" y1="1.27" x2="1.905" y2="1.27" width="0.1524" layer="21"/>
<wire x1="1.905" y1="1.27" x2="2.54" y2="0.635" width="0.1524" layer="21"/>
<wire x1="2.54" y1="0.635" x2="2.54" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="2.54" y1="-0.635" x2="1.905" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="1.905" y1="-1.27" x2="0.635" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="0.635" y1="-1.27" x2="0" y2="-0.635" width="0.1524" layer="21"/>
<pad name="1" x="-1.27" y="0" drill="1.016" shape="long" rot="R90"/>
<pad name="2" x="1.27" y="0" drill="1.016" shape="long" rot="R90"/>
<text x="-2.6162" y="1.8288" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="-2.54" y="-3.175" size="1.27" layer="27">&gt;VALUE</text>
<rectangle x1="-1.524" y1="-0.254" x2="-1.016" y2="0.254" layer="51"/>
<rectangle x1="1.016" y1="-0.254" x2="1.524" y2="0.254" layer="51"/>
</package>
<package name="1X02/90">
<description>&lt;b&gt;PIN HEADER&lt;/b&gt;</description>
<wire x1="-2.54" y1="-1.905" x2="0" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="0" y1="-1.905" x2="0" y2="0.635" width="0.1524" layer="21"/>
<wire x1="0" y1="0.635" x2="-2.54" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-2.54" y1="0.635" x2="-2.54" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-1.27" y1="6.985" x2="-1.27" y2="1.27" width="0.762" layer="21"/>
<wire x1="0" y1="-1.905" x2="2.54" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="2.54" y1="-1.905" x2="2.54" y2="0.635" width="0.1524" layer="21"/>
<wire x1="2.54" y1="0.635" x2="0" y2="0.635" width="0.1524" layer="21"/>
<wire x1="1.27" y1="6.985" x2="1.27" y2="1.27" width="0.762" layer="21"/>
<pad name="1" x="-1.27" y="-3.81" drill="1.016" shape="long" rot="R90"/>
<pad name="2" x="1.27" y="-3.81" drill="1.016" shape="long" rot="R90"/>
<text x="-3.175" y="-3.81" size="1.27" layer="25" ratio="10" rot="R90">&gt;NAME</text>
<text x="4.445" y="-3.81" size="1.27" layer="27" rot="R90">&gt;VALUE</text>
<rectangle x1="-1.651" y1="0.635" x2="-0.889" y2="1.143" layer="21"/>
<rectangle x1="0.889" y1="0.635" x2="1.651" y2="1.143" layer="21"/>
<rectangle x1="-1.651" y1="-2.921" x2="-0.889" y2="-1.905" layer="21"/>
<rectangle x1="0.889" y1="-2.921" x2="1.651" y2="-1.905" layer="21"/>
</package>
</packages>
<symbols>
<symbol name="PINHD2">
<wire x1="-6.35" y1="-2.54" x2="1.27" y2="-2.54" width="0.4064" layer="94"/>
<wire x1="1.27" y1="-2.54" x2="1.27" y2="5.08" width="0.4064" layer="94"/>
<wire x1="1.27" y1="5.08" x2="-6.35" y2="5.08" width="0.4064" layer="94"/>
<wire x1="-6.35" y1="5.08" x2="-6.35" y2="-2.54" width="0.4064" layer="94"/>
<text x="-6.35" y="5.715" size="1.778" layer="95">&gt;NAME</text>
<text x="-6.35" y="-5.08" size="1.778" layer="96">&gt;VALUE</text>
<pin name="1" x="-2.54" y="2.54" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="2" x="-2.54" y="0" visible="pad" length="short" direction="pas" function="dot"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="PINHD-1X2" prefix="JP" uservalue="yes">
<description>&lt;b&gt;PIN HEADER&lt;/b&gt;</description>
<gates>
<gate name="G$1" symbol="PINHD2" x="0" y="0"/>
</gates>
<devices>
<device name="" package="1X02">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="/90" package="1X02/90">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="supply1">
<description>&lt;b&gt;Supply Symbols&lt;/b&gt;&lt;p&gt;
 GND, VCC, 0V, +5V, -5V, etc.&lt;p&gt;
 Please keep in mind, that these devices are necessary for the
 automatic wiring of the supply signals.&lt;p&gt;
 The pin name defined in the symbol is identical to the net which is to be wired automatically.&lt;p&gt;
 In this library the device names are the same as the pin names of the symbols, therefore the correct signal names appear next to the supply symbols in the schematic.&lt;p&gt;
 &lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
</packages>
<symbols>
<symbol name="VCC">
<wire x1="1.27" y1="-1.905" x2="0" y2="0" width="0.254" layer="94"/>
<wire x1="0" y1="0" x2="-1.27" y2="-1.905" width="0.254" layer="94"/>
<text x="-2.54" y="-2.54" size="1.778" layer="96" rot="R90">&gt;VALUE</text>
<pin name="VCC" x="0" y="-2.54" visible="off" length="short" direction="sup" rot="R90"/>
</symbol>
<symbol name="GND">
<wire x1="-1.905" y1="0" x2="1.905" y2="0" width="0.254" layer="94"/>
<text x="-2.54" y="-2.54" size="1.778" layer="96">&gt;VALUE</text>
<pin name="GND" x="0" y="2.54" visible="off" length="short" direction="sup" rot="R270"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="VCC" prefix="P+">
<description>&lt;b&gt;SUPPLY SYMBOL&lt;/b&gt;</description>
<gates>
<gate name="VCC" symbol="VCC" x="0" y="0"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="GND" prefix="GND">
<description>&lt;b&gt;SUPPLY SYMBOL&lt;/b&gt;</description>
<gates>
<gate name="1" symbol="GND" x="0" y="0"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
</libraries>
<attributes>
</attributes>
<variantdefs>
</variantdefs>
<classes>
<class number="0" name="default" width="0" drill="0">
</class>
</classes>
<parts>
<part name="S1" library="trisolx-ks" deviceset="SOLAR_WINGS" device="SMD"/>
<part name="S2" library="trisolx-ks" deviceset="SOLAR_WINGS" device="SMD"/>
<part name="S3" library="trisolx-ks" deviceset="SOLAR_WINGS" device="SMD"/>
<part name="S4" library="trisolx-ks" deviceset="SOLAR_WINGS" device="SMD"/>
<part name="S5" library="trisolx-ks" deviceset="SOLAR_WINGS" device="SMD"/>
<part name="JP1" library="pinhead" deviceset="PINHD-1X2" device=""/>
<part name="P+1" library="supply1" deviceset="VCC" device=""/>
<part name="GND1" library="supply1" deviceset="GND" device=""/>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
<instance part="S1" gate="G$1" x="17.78" y="81.28"/>
<instance part="S2" gate="G$1" x="17.78" y="66.04"/>
<instance part="S3" gate="G$1" x="17.78" y="53.34"/>
<instance part="S4" gate="G$1" x="17.78" y="38.1"/>
<instance part="S5" gate="G$1" x="17.78" y="22.86"/>
<instance part="JP1" gate="G$1" x="76.2" y="48.26"/>
<instance part="P+1" gate="VCC" x="33.02" y="93.98"/>
<instance part="GND1" gate="1" x="7.62" y="2.54"/>
</instances>
<busses>
</busses>
<nets>
<net name="GND" class="0">
<segment>
<pinref part="S1" gate="G$1" pin="NEG"/>
<pinref part="GND1" gate="1" pin="GND"/>
<wire x1="10.16" y1="81.28" x2="7.62" y2="81.28" width="0.1524" layer="91"/>
<wire x1="7.62" y1="81.28" x2="7.62" y2="66.04" width="0.1524" layer="91"/>
<pinref part="S5" gate="G$1" pin="NEG"/>
<wire x1="7.62" y1="66.04" x2="7.62" y2="53.34" width="0.1524" layer="91"/>
<wire x1="7.62" y1="53.34" x2="7.62" y2="38.1" width="0.1524" layer="91"/>
<wire x1="7.62" y1="38.1" x2="7.62" y2="22.86" width="0.1524" layer="91"/>
<wire x1="7.62" y1="22.86" x2="7.62" y2="5.08" width="0.1524" layer="91"/>
<wire x1="10.16" y1="22.86" x2="7.62" y2="22.86" width="0.1524" layer="91"/>
<junction x="7.62" y="22.86"/>
<pinref part="S4" gate="G$1" pin="NEG"/>
<wire x1="10.16" y1="38.1" x2="7.62" y2="38.1" width="0.1524" layer="91"/>
<junction x="7.62" y="38.1"/>
<pinref part="S3" gate="G$1" pin="NEG"/>
<wire x1="10.16" y1="53.34" x2="7.62" y2="53.34" width="0.1524" layer="91"/>
<junction x="7.62" y="53.34"/>
<pinref part="S2" gate="G$1" pin="NEG"/>
<wire x1="10.16" y1="66.04" x2="7.62" y2="66.04" width="0.1524" layer="91"/>
<junction x="7.62" y="66.04"/>
<pinref part="JP1" gate="G$1" pin="2"/>
<wire x1="73.66" y1="48.26" x2="50.8" y2="48.26" width="0.1524" layer="91"/>
<wire x1="50.8" y1="48.26" x2="50.8" y2="5.08" width="0.1524" layer="91"/>
<wire x1="50.8" y1="5.08" x2="7.62" y2="5.08" width="0.1524" layer="91"/>
<junction x="7.62" y="5.08"/>
</segment>
</net>
<net name="VCC" class="0">
<segment>
<pinref part="S1" gate="G$1" pin="POS"/>
<wire x1="22.86" y1="81.28" x2="33.02" y2="81.28" width="0.1524" layer="91"/>
<wire x1="33.02" y1="81.28" x2="40.64" y2="81.28" width="0.1524" layer="91"/>
<wire x1="40.64" y1="81.28" x2="40.64" y2="66.04" width="0.1524" layer="91"/>
<pinref part="S5" gate="G$1" pin="POS"/>
<wire x1="40.64" y1="66.04" x2="40.64" y2="60.96" width="0.1524" layer="91"/>
<wire x1="40.64" y1="60.96" x2="40.64" y2="53.34" width="0.1524" layer="91"/>
<wire x1="40.64" y1="53.34" x2="40.64" y2="38.1" width="0.1524" layer="91"/>
<wire x1="40.64" y1="38.1" x2="40.64" y2="22.86" width="0.1524" layer="91"/>
<wire x1="40.64" y1="22.86" x2="22.86" y2="22.86" width="0.1524" layer="91"/>
<pinref part="S2" gate="G$1" pin="POS"/>
<wire x1="22.86" y1="66.04" x2="40.64" y2="66.04" width="0.1524" layer="91"/>
<junction x="40.64" y="66.04"/>
<pinref part="S3" gate="G$1" pin="POS"/>
<wire x1="22.86" y1="53.34" x2="40.64" y2="53.34" width="0.1524" layer="91"/>
<junction x="40.64" y="53.34"/>
<pinref part="S4" gate="G$1" pin="POS"/>
<wire x1="22.86" y1="38.1" x2="40.64" y2="38.1" width="0.1524" layer="91"/>
<junction x="40.64" y="38.1"/>
<pinref part="P+1" gate="VCC" pin="VCC"/>
<wire x1="33.02" y1="91.44" x2="33.02" y2="81.28" width="0.1524" layer="91"/>
<junction x="33.02" y="81.28"/>
<pinref part="JP1" gate="G$1" pin="1"/>
<wire x1="73.66" y1="50.8" x2="45.72" y2="50.8" width="0.1524" layer="91"/>
<wire x1="45.72" y1="50.8" x2="45.72" y2="60.96" width="0.1524" layer="91"/>
<wire x1="45.72" y1="60.96" x2="40.64" y2="60.96" width="0.1524" layer="91"/>
<junction x="40.64" y="60.96"/>
</segment>
</net>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
</eagle>
