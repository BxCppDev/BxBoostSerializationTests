#!/usr/bin/env bash
opwd=$(pwd)
echo >&2 "[info] opwd = '${opwd}'"
build_dir=${opwd}/_build.d
install_dir=${opwd}/_install.d

if [ -d ${build_dir} ]; then
    rm -fr ${build_dir}
fi

if [ -d ${install_dir} ]; then
    rm -fr ${install_dir}
fi

find ${opwd} -name "*~" -exec rm -f \{\} \;

exit 0

# end
