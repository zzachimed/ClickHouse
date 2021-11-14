#!/bin/bash

grep -v -P '^#' queries.sql | sed -e 's/{table}/test.hits3/' | while read query; do

    for i in {1..3}; do
        if [[ $i == 1 ]]
        then
            CACHE=false
        else
            CACHE=true
        fi

        curl -sS -v "https://clickhouse-test.hydrolix.live/query?storage.fs.cache.enabled=${CACHE}&storage.fs.http.keep_alive=true" --data-binary "$query" 2>&1 | grep -P 'exec_time=\d+|clickhouse-exception' || echo FAIL
    done;
done;
