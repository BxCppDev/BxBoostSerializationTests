#!/usr/bin/env bash
boost_install_dir=

opwd=$(pwd)
echo >&2 "[info] opwd = '${opwd}'"
build_dir=${opwd}/_build.d
install_dir=${opwd}/_install.d
source_dir=${opwd}

function app_exit()
{
    local error_code=$1
    if [ "x${error_code}" = "x" ]; then
	error_code=0
    fi
    shift 1
    local error_msg="$@"
    if [ ${error_code} -ne 0 -a -n "${error_msg}" ]; then
	echo >&2 "[error] ${error_msg}"
    fi
    exit ${error_code}
}

function app_parse()
{
    while [ -n "$1" ]; do
	local arg="$1"
	if [ "${arg}" = "--boost-install-dir" ]; then
	    shift 1
	    boost_install_dir=$1
	else
	    echo >&2 "[error] Unsupported comand line option '${arg}'!"
	    return 1
	fi
	shift 1
    done
    return 0
}

app_parse $@
if [ $? -ne 0 ]; then
    echo >&2 "[error] Command line parsing failed!"
    app_exit 1
fi

echo >&2 "[info] source_dir  = '${source_dir}'"
echo >&2 "[info] build_dir   = '${build_dir}'"
echo >&2 "[info] install_dir = '${install_dir}'"
echo >&2 "[info] boost_install_dir = '${boost_install_dir}'"

mkdir -p ${build_dir}
cd ${build_dir}


if [ "x${boost_install_dir}" != "x" ]; then
    boost_opts=-DBOOST_ROOT:PATH=${boost_install_dir}
fi

cmake \
    -DCMAKE_INSTALL_PREFIX:PATH=${install_dir} \
    ${boost_opts} \
    ${source_dir}

make

make install

tree ${install_dir}

app_exit 0

# end
