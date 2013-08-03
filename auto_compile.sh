#!/bin/bash

jcompileAndRun()
{
		file=$1
		echo ${file} | grep -q "\."
		if [ $? -eq 0 ];then		
			suffix=${file##*.}
			if [ ${suffix} = 'c'  ];then
				echo "------------------------ begin compile ${file} --------------------------------------"
					gcc  -o  "bin/${file%.*}.out"  ${file}  -std=c99
					flag=$?
				echo "----------------------------------- end --------------------------------------"

				echo "######################### run compile ${file%.*}.out ###################################"
					[[ ${flag} -eq 0 ]] && ./bin/"${file%.*}.out"  || echo "compile error"
					echo ""
				echo "#################################### end ###############################################"
			fi
		fi
}

# if [  -n "$1" ]; then
# 	compileAndRun $1
# else
# 	dir=$(pwd)
# 	files=$(ls ${dir})
# 	for file in ${files}
# 	do
# 		compileAndRun $file
# 	done
# fi
