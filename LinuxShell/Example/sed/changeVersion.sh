#!/bin/sh

if [ $# != 3 ]; then
	echo "Usage: changeVersion file VERSION DATE"
	echo "VERSION FORM : \"x.x.x\""
	echo "DATE FORM : \"x/x/x\""
	exit
fi

cFile=$1
cVersion=$2
cDate=$3

cMAJOR=`echo ${cVersion} | awk -F "." '{print $1}'`
cMINOR=`echo ${cVersion} | awk -F "." '{print $2}'`
cLAST=`echo ${cVersion} | awk -F "." '{print $3}'`

creDate=`echo ${cDate} | awk -F "/" '{print $1}'`"\/"`echo ${cDate} | awk -F "/" '{print $2}'`"\/"`echo ${cDate} | awk -F "/" '{print $3}'`

sed -i "s/MAJOR_VERSION__[[:space:]]\{1,\}[0-9]\{1,\}/MAJOR_VERSION__\t"${cMAJOR}"/" ${cFile}
sed -i "s/MINOR_VERSION__[[:space:]]\{1,\}[0-9]\{1,\}/MINOR_VERSION__\t"${cMINOR}"/" ${cFile}
sed -i "s/LAST_VERSION__[[:space:]]\{1,\}[0-9]\{1,\}/LAST_VERSION__\t"${cLAST}"/" ${cFile}
sed -i "s/CODE_VERSION__[[:space:]]\{1,\}[0-9\.\"]\{1,\}/CODE_VERSION__\t\""${cVersion}"\"/" ${cFile}
sed -i "s/CODE_DATE__[[:space:]]\{1,\}[0-9\/\"]\{1,\}/CODE_DATE__\t\""${creDate}"\"/" ${cFile}