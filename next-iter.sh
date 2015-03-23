#! /usr/bin/bash

./git-clean

curr_max=1

### find current highest directory ###
for d in */
do
  if [ $curr_max -lt ${d%/} ]
    then curr_max=${d%/}
  fi
done

echo "current iteration: ${curr_max}"
new_dir=$((curr_max+1))
echo "next iteration: ${new_dir}"

cp -r ${curr_max} ${new_dir}
git add *
git commit -m "Stage next iteration"
