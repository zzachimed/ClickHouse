#pragma once

#include <config.h>

#if USE_AWS_S3

#    include <IO/ReadBufferFromS3.h>
#    include <IO/ReadHelpers.h>
#    include <IO/S3Common.h>

#    include <Formats/FormatFactory.h>

#    include <Storages/StorageS3.h>
#    include <aws/core/auth/AWSCredentials.h>
#    include <aws/s3/S3Client.h>
#    include <aws/s3/model/ListObjectsV2Request.h>


class ReadBuffer;

namespace DB
{

struct S3DataLakeMetaReadHelper
{
    static std::shared_ptr<ReadBuffer>
    createReadBuffer(const String & key, ContextPtr context, const StorageS3::Configuration & base_configuration);

    static std::vector<String>
    listFilesMatchSuffix(const StorageS3::Configuration & base_configuration, const String & directory, const String & suffix);

    static std::vector<String> listFiles(const StorageS3::Configuration & configuration);
};
}

#endif
