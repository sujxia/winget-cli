// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.
#pragma once
#include "Microsoft/Schema/ISQLiteIndex.h"
#include "Microsoft/Schema/1_0/Interface.h"


namespace AppInstaller::Repository::Microsoft::Schema::V1_1
{
    // Interface to this schema version exposed through ISQLiteIndex.
    struct Interface : public V1_0::Interface
    {
        // Version 1.0
        Schema::Version GetVersion() const override;
        void CreateTables(SQLite::Connection& connection) override;
        SQLite::rowid_t AddManifest(SQLite::Connection& connection, const Manifest::Manifest& manifest, const std::filesystem::path& relativePath) override;
        std::pair<bool, SQLite::rowid_t> UpdateManifest(SQLite::Connection& connection, const Manifest::Manifest& manifest, const std::filesystem::path& relativePath) override;
        SQLite::rowid_t RemoveManifest(SQLite::Connection& connection, const Manifest::Manifest& manifest, const std::filesystem::path& relativePath) override;
        void PrepareForPackaging(SQLite::Connection& connection) override;
        SearchResult Search(SQLite::Connection& connection, const SearchRequest& request) override;

    protected:
        std::unique_ptr<V1_0::SearchResultsTable> CreateSearchResultsTable(SQLite::Connection& connection) const override;
        void PerformQuerySearch(V1_0::SearchResultsTable& resultsTable, const RequestMatch& query) const override;
    };
}
