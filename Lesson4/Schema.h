﻿#pragma once

#using <mscorlib.dll>
#using <System.dll>
#using <System.Data.dll>
#using <System.Xml.dll>

using namespace System::Security::Permissions;
[assembly:SecurityPermissionAttribute(SecurityAction::RequestMinimum, SkipVerification=false)];
// 
// This source code was auto-generated by xsd, Version=4.6.1055.0.
// 
namespace Lesson4 {
    using namespace System;
    ref class NewDataSet;
    
    
    /// <summary>
///Represents a strongly typed in-memory cache of data.
///</summary>
    [System::Serializable, 
    System::ComponentModel::DesignerCategoryAttribute(L"code"), 
    System::ComponentModel::ToolboxItem(true), 
    System::Xml::Serialization::XmlSchemaProviderAttribute(L"GetTypedDataSetSchema"), 
    System::Xml::Serialization::XmlRootAttribute(L"NewDataSet"), 
    System::ComponentModel::Design::HelpKeywordAttribute(L"vs.data.DataSet")]
    public ref class NewDataSet : public ::System::Data::DataSet {
        public : ref class UserDataTable;
        public : ref class UserRow;
        public : ref class UserRowChangeEvent;
        
        private: Lesson4::NewDataSet::UserDataTable^  tableUser;
        
        private: ::System::Data::SchemaSerializationMode _schemaSerializationMode;
        
        public : [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        delegate System::Void UserRowChangeEventHandler(::System::Object^  sender, Lesson4::NewDataSet::UserRowChangeEvent^  e);
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        NewDataSet();
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        NewDataSet(::System::Runtime::Serialization::SerializationInfo^  info, ::System::Runtime::Serialization::StreamingContext context);
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0"), 
        System::ComponentModel::Browsable(false), 
        System::ComponentModel::DesignerSerializationVisibility(::System::ComponentModel::DesignerSerializationVisibility::Content)]
        property Lesson4::NewDataSet::UserDataTable^  User {
            Lesson4::NewDataSet::UserDataTable^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0"), 
        System::ComponentModel::BrowsableAttribute(true), 
        System::ComponentModel::DesignerSerializationVisibilityAttribute(::System::ComponentModel::DesignerSerializationVisibility::Visible)]
        virtual property ::System::Data::SchemaSerializationMode SchemaSerializationMode {
            ::System::Data::SchemaSerializationMode get() override;
            System::Void set(::System::Data::SchemaSerializationMode value) override;
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0"), 
        System::ComponentModel::DesignerSerializationVisibilityAttribute(::System::ComponentModel::DesignerSerializationVisibility::Hidden)]
        property ::System::Data::DataTableCollection^  Tables {
            ::System::Data::DataTableCollection^  get() new;
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0"), 
        System::ComponentModel::DesignerSerializationVisibilityAttribute(::System::ComponentModel::DesignerSerializationVisibility::Hidden)]
        property ::System::Data::DataRelationCollection^  Relations {
            ::System::Data::DataRelationCollection^  get() new;
        }
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Void InitializeDerivedDataSet() override;
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Data::DataSet^  Clone() override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Boolean ShouldSerializeTables() override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Boolean ShouldSerializeRelations() override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Void ReadXmlSerializable(::System::Xml::XmlReader^  reader) override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Xml::Schema::XmlSchema^  GetSchemaSerializable() override;
        
        internal: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void InitVars();
        
        internal: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void InitVars(::System::Boolean initTable);
        
        private: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void InitClass();
        
        private: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Boolean ShouldSerializeUser();
        
        private: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void SchemaChanged(::System::Object^  sender, ::System::ComponentModel::CollectionChangeEventArgs^  e);
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        static ::System::Xml::Schema::XmlSchemaComplexType^  GetTypedDataSetSchema(::System::Xml::Schema::XmlSchemaSet^  xs);
        
        public : /// <summary>
///Represents the strongly named DataTable class.
///</summary>
        [System::Serializable, 
        System::Xml::Serialization::XmlSchemaProviderAttribute(L"GetTypedTableSchema")]
        ref class UserDataTable : public ::System::Data::DataTable, public ::System::Collections::IEnumerable {
            
            private: ::System::Data::DataColumn^  columnusername;
            
            private: ::System::Data::DataColumn^  columnpassword;
            
            public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
            event Lesson4::NewDataSet::UserRowChangeEventHandler^  UserRowChanging;
            
            public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
            event Lesson4::NewDataSet::UserRowChangeEventHandler^  UserRowChanged;
            
            public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
            event Lesson4::NewDataSet::UserRowChangeEventHandler^  UserRowDeleting;
            
            public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
            event Lesson4::NewDataSet::UserRowChangeEventHandler^  UserRowDeleted;
            
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
            UserDataTable();
            internal: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
            UserDataTable(::System::Data::DataTable^  table);
            protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
            UserDataTable(::System::Runtime::Serialization::SerializationInfo^  info, ::System::Runtime::Serialization::StreamingContext context);
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
            System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
            property ::System::Data::DataColumn^  usernameColumn {
                ::System::Data::DataColumn^  get();
            }
            
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
            System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
            property ::System::Data::DataColumn^  passwordColumn {
                ::System::Data::DataColumn^  get();
            }
            
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
            System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0"), 
            System::ComponentModel::Browsable(false)]
            property ::System::Int32 Count {
                ::System::Int32 get();
            }
            
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
            System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
            property Lesson4::NewDataSet::UserRow^  default [::System::Int32 ] {
                Lesson4::NewDataSet::UserRow^  get(::System::Int32 index);
            }
            
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
            ::System::Void AddUserRow(Lesson4::NewDataSet::UserRow^  row);
            
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
            Lesson4::NewDataSet::UserRow^  AddUserRow(System::String^  username, System::String^  password);
            
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
            virtual ::System::Collections::IEnumerator^  GetEnumerator();
            
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
            virtual ::System::Data::DataTable^  Clone() override;
            
            protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
            virtual ::System::Data::DataTable^  CreateInstance() override;
            
            internal: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
            ::System::Void InitVars();
            
            private: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
            ::System::Void InitClass();
            
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
            Lesson4::NewDataSet::UserRow^  NewUserRow();
            
            protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
            virtual ::System::Data::DataRow^  NewRowFromBuilder(::System::Data::DataRowBuilder^  builder) override;
            
            protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
            virtual ::System::Type^  GetRowType() override;
            
            protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
            virtual ::System::Void OnRowChanged(::System::Data::DataRowChangeEventArgs^  e) override;
            
            protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
            virtual ::System::Void OnRowChanging(::System::Data::DataRowChangeEventArgs^  e) override;
            
            protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
            virtual ::System::Void OnRowDeleted(::System::Data::DataRowChangeEventArgs^  e) override;
            
            protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
            virtual ::System::Void OnRowDeleting(::System::Data::DataRowChangeEventArgs^  e) override;
            
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
            ::System::Void RemoveUserRow(Lesson4::NewDataSet::UserRow^  row);
            
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
            static ::System::Xml::Schema::XmlSchemaComplexType^  GetTypedTableSchema(::System::Xml::Schema::XmlSchemaSet^  xs);
        };
        
        public : /// <summary>
///Represents strongly named DataRow class.
///</summary>
        ref class UserRow : public ::System::Data::DataRow {
            
            private: Lesson4::NewDataSet::UserDataTable^  tableUser;
            
            internal: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
            UserRow(::System::Data::DataRowBuilder^  rb);
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
            System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
            property System::String^  username {
                System::String^  get();
                System::Void set(System::String^  value);
            }
            
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
            System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
            property System::String^  password {
                System::String^  get();
                System::Void set(System::String^  value);
            }
        };
        
        public : /// <summary>
///Row event argument class
///</summary>
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ref class UserRowChangeEvent : public ::System::EventArgs {
            
            private: Lesson4::NewDataSet::UserRow^  eventRow;
            
            private: ::System::Data::DataRowAction eventAction;
            
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
            UserRowChangeEvent(Lesson4::NewDataSet::UserRow^  row, ::System::Data::DataRowAction action);
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
            System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
            property Lesson4::NewDataSet::UserRow^  Row {
                Lesson4::NewDataSet::UserRow^  get();
            }
            
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
            System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
            property ::System::Data::DataRowAction Action {
                ::System::Data::DataRowAction get();
            }
        };
    };
}
namespace Lesson4 {
    
    
    inline NewDataSet::NewDataSet() {
        this->BeginInit();
        this->InitClass();
        ::System::ComponentModel::CollectionChangeEventHandler^  schemaChangedHandler = gcnew ::System::ComponentModel::CollectionChangeEventHandler(this, &Lesson4::NewDataSet::SchemaChanged);
        __super::Tables->CollectionChanged += schemaChangedHandler;
        __super::Relations->CollectionChanged += schemaChangedHandler;
        this->EndInit();
    }
    
    inline NewDataSet::NewDataSet(::System::Runtime::Serialization::SerializationInfo^  info, ::System::Runtime::Serialization::StreamingContext context) : 
            ::System::Data::DataSet(info, context, false) {
        if (this->IsBinarySerialized(info, context) == true) {
            this->InitVars(false);
            ::System::ComponentModel::CollectionChangeEventHandler^  schemaChangedHandler1 = gcnew ::System::ComponentModel::CollectionChangeEventHandler(this, &Lesson4::NewDataSet::SchemaChanged);
            this->Tables->CollectionChanged += schemaChangedHandler1;
            this->Relations->CollectionChanged += schemaChangedHandler1;
            return;
        }
        ::System::String^  strSchema = (cli::safe_cast<::System::String^  >(info->GetValue(L"XmlSchema", ::System::String::typeid)));
        if (this->DetermineSchemaSerializationMode(info, context) == ::System::Data::SchemaSerializationMode::IncludeSchema) {
            ::System::Data::DataSet^  ds = (gcnew ::System::Data::DataSet());
            ds->ReadXmlSchema((gcnew ::System::Xml::XmlTextReader((gcnew ::System::IO::StringReader(strSchema)))));
            if (ds->Tables[L"User"] != nullptr) {
                __super::Tables->Add((gcnew Lesson4::NewDataSet::UserDataTable(ds->Tables[L"User"])));
            }
            this->DataSetName = ds->DataSetName;
            this->Prefix = ds->Prefix;
            this->Namespace = ds->Namespace;
            this->Locale = ds->Locale;
            this->CaseSensitive = ds->CaseSensitive;
            this->EnforceConstraints = ds->EnforceConstraints;
            this->Merge(ds, false, ::System::Data::MissingSchemaAction::Add);
            this->InitVars();
        }
        else {
            this->ReadXmlSchema((gcnew ::System::Xml::XmlTextReader((gcnew ::System::IO::StringReader(strSchema)))));
        }
        this->GetSerializationData(info, context);
        ::System::ComponentModel::CollectionChangeEventHandler^  schemaChangedHandler = gcnew ::System::ComponentModel::CollectionChangeEventHandler(this, &Lesson4::NewDataSet::SchemaChanged);
        __super::Tables->CollectionChanged += schemaChangedHandler;
        this->Relations->CollectionChanged += schemaChangedHandler;
    }
    
    inline Lesson4::NewDataSet::UserDataTable^  NewDataSet::User::get() {
        return this->tableUser;
    }
    
    inline ::System::Data::SchemaSerializationMode NewDataSet::SchemaSerializationMode::get() {
        return this->_schemaSerializationMode;
    }
    inline System::Void NewDataSet::SchemaSerializationMode::set(::System::Data::SchemaSerializationMode value) {
        this->_schemaSerializationMode = __identifier(value);
    }
    
    inline ::System::Data::DataTableCollection^  NewDataSet::Tables::get() {
        return __super::Tables;
    }
    
    inline ::System::Data::DataRelationCollection^  NewDataSet::Relations::get() {
        return __super::Relations;
    }
    
    inline ::System::Void NewDataSet::InitializeDerivedDataSet() {
        this->BeginInit();
        this->InitClass();
        this->EndInit();
    }
    
    inline ::System::Data::DataSet^  NewDataSet::Clone() {
        Lesson4::NewDataSet^  cln = (cli::safe_cast<Lesson4::NewDataSet^  >(__super::Clone()));
        cln->InitVars();
        cln->SchemaSerializationMode = this->SchemaSerializationMode;
        return cln;
    }
    
    inline ::System::Boolean NewDataSet::ShouldSerializeTables() {
        return false;
    }
    
    inline ::System::Boolean NewDataSet::ShouldSerializeRelations() {
        return false;
    }
    
    inline ::System::Void NewDataSet::ReadXmlSerializable(::System::Xml::XmlReader^  reader) {
        if (this->DetermineSchemaSerializationMode(reader) == ::System::Data::SchemaSerializationMode::IncludeSchema) {
            this->Reset();
            ::System::Data::DataSet^  ds = (gcnew ::System::Data::DataSet());
            ds->ReadXml(reader);
            if (ds->Tables[L"User"] != nullptr) {
                __super::Tables->Add((gcnew Lesson4::NewDataSet::UserDataTable(ds->Tables[L"User"])));
            }
            this->DataSetName = ds->DataSetName;
            this->Prefix = ds->Prefix;
            this->Namespace = ds->Namespace;
            this->Locale = ds->Locale;
            this->CaseSensitive = ds->CaseSensitive;
            this->EnforceConstraints = ds->EnforceConstraints;
            this->Merge(ds, false, ::System::Data::MissingSchemaAction::Add);
            this->InitVars();
        }
        else {
            this->ReadXml(reader);
            this->InitVars();
        }
    }
    
    inline ::System::Xml::Schema::XmlSchema^  NewDataSet::GetSchemaSerializable() {
        ::System::IO::MemoryStream^  stream = (gcnew ::System::IO::MemoryStream());
        this->WriteXmlSchema((gcnew ::System::Xml::XmlTextWriter(stream, nullptr)));
        stream->Position = 0;
        return ::System::Xml::Schema::XmlSchema::Read((gcnew ::System::Xml::XmlTextReader(stream)), nullptr);
    }
    
    inline ::System::Void NewDataSet::InitVars() {
        this->InitVars(true);
    }
    
    inline ::System::Void NewDataSet::InitVars(::System::Boolean initTable) {
        this->tableUser = (cli::safe_cast<Lesson4::NewDataSet::UserDataTable^  >(__super::Tables[L"User"]));
        if (initTable == true) {
            if (this->tableUser != nullptr) {
                this->tableUser->InitVars();
            }
        }
    }
    
    inline ::System::Void NewDataSet::InitClass() {
        this->DataSetName = L"NewDataSet";
        this->Prefix = L"";
        this->Locale = (gcnew ::System::Globalization::CultureInfo(L""));
        this->EnforceConstraints = true;
        this->SchemaSerializationMode = ::System::Data::SchemaSerializationMode::IncludeSchema;
        this->tableUser = (gcnew Lesson4::NewDataSet::UserDataTable());
        __super::Tables->Add(this->tableUser);
    }
    
    inline ::System::Boolean NewDataSet::ShouldSerializeUser() {
        return false;
    }
    
    inline ::System::Void NewDataSet::SchemaChanged(::System::Object^  sender, ::System::ComponentModel::CollectionChangeEventArgs^  e) {
        if (e->Action == ::System::ComponentModel::CollectionChangeAction::Remove) {
            this->InitVars();
        }
    }
    
    inline ::System::Xml::Schema::XmlSchemaComplexType^  NewDataSet::GetTypedDataSetSchema(::System::Xml::Schema::XmlSchemaSet^  xs) {
        Lesson4::NewDataSet^  ds = (gcnew Lesson4::NewDataSet());
        ::System::Xml::Schema::XmlSchemaComplexType^  type = (gcnew ::System::Xml::Schema::XmlSchemaComplexType());
        ::System::Xml::Schema::XmlSchemaSequence^  sequence = (gcnew ::System::Xml::Schema::XmlSchemaSequence());
        ::System::Xml::Schema::XmlSchemaAny^  any = (gcnew ::System::Xml::Schema::XmlSchemaAny());
        any->Namespace = ds->Namespace;
        sequence->Items->Add(any);
        type->Particle = sequence;
        ::System::Xml::Schema::XmlSchema^  dsSchema = ds->GetSchemaSerializable();
        if (xs->Contains(dsSchema->TargetNamespace)) {
            ::System::IO::MemoryStream^  s1 = (gcnew ::System::IO::MemoryStream());
            ::System::IO::MemoryStream^  s2 = (gcnew ::System::IO::MemoryStream());
            try {
                ::System::Xml::Schema::XmlSchema^  schema = nullptr;
                dsSchema->Write(s1);
                for (                ::System::Collections::IEnumerator^  schemas = xs->Schemas(dsSchema->TargetNamespace)->GetEnumerator(); schemas->MoveNext();                 ) {
                    schema = (cli::safe_cast<::System::Xml::Schema::XmlSchema^  >(schemas->Current));
                    s2->SetLength(0);
                    schema->Write(s2);
                    if (s1->Length == s2->Length) {
                        s1->Position = 0;
                        s2->Position = 0;
                        for (                        ; ((s1->Position != s1->Length) 
                                    && (s1->ReadByte() == s2->ReadByte()));                         ) {
                            ;
                        }
                        if (s1->Position == s1->Length) {
                            return type;
                        }
                    }
                }
            }
            finally {
                if (s1 != nullptr) {
                    s1->Close();
                }
                if (s2 != nullptr) {
                    s2->Close();
                }
            }
        }
        xs->Add(dsSchema);
        return type;
    }
    
    
    inline NewDataSet::UserDataTable::UserDataTable() {
        this->TableName = L"User";
        this->BeginInit();
        this->InitClass();
        this->EndInit();
    }
    
    inline NewDataSet::UserDataTable::UserDataTable(::System::Data::DataTable^  table) {
        this->TableName = table->TableName;
        if (table->CaseSensitive != table->DataSet->CaseSensitive) {
            this->CaseSensitive = table->CaseSensitive;
        }
        if (table->Locale->ToString() != table->DataSet->Locale->ToString()) {
            this->Locale = table->Locale;
        }
        if (table->Namespace != table->DataSet->Namespace) {
            this->Namespace = table->Namespace;
        }
        this->Prefix = table->Prefix;
        this->MinimumCapacity = table->MinimumCapacity;
    }
    
    inline NewDataSet::UserDataTable::UserDataTable(::System::Runtime::Serialization::SerializationInfo^  info, ::System::Runtime::Serialization::StreamingContext context) : 
            ::System::Data::DataTable(info, context) {
        this->InitVars();
    }
    
    inline ::System::Data::DataColumn^  NewDataSet::UserDataTable::usernameColumn::get() {
        return this->columnusername;
    }
    
    inline ::System::Data::DataColumn^  NewDataSet::UserDataTable::passwordColumn::get() {
        return this->columnpassword;
    }
    
    inline ::System::Int32 NewDataSet::UserDataTable::Count::get() {
        return this->Rows->Count;
    }
    
    inline Lesson4::NewDataSet::UserRow^  NewDataSet::UserDataTable::default::get(::System::Int32 index) {
        return (cli::safe_cast<Lesson4::NewDataSet::UserRow^  >(this->Rows[index]));
    }
    
    inline ::System::Void NewDataSet::UserDataTable::AddUserRow(Lesson4::NewDataSet::UserRow^  row) {
        this->Rows->Add(row);
    }
    
    inline Lesson4::NewDataSet::UserRow^  NewDataSet::UserDataTable::AddUserRow(System::String^  username, System::String^  password) {
        Lesson4::NewDataSet::UserRow^  rowUserRow = (cli::safe_cast<Lesson4::NewDataSet::UserRow^  >(this->NewRow()));
        cli::array< ::System::Object^  >^  columnValuesArray = gcnew cli::array< ::System::Object^  >(2) {username, password};
        rowUserRow->ItemArray = columnValuesArray;
        this->Rows->Add(rowUserRow);
        return rowUserRow;
    }
    
    inline ::System::Collections::IEnumerator^  NewDataSet::UserDataTable::GetEnumerator() {
        return this->Rows->GetEnumerator();
    }
    
    inline ::System::Data::DataTable^  NewDataSet::UserDataTable::Clone() {
        Lesson4::NewDataSet::UserDataTable^  cln = (cli::safe_cast<Lesson4::NewDataSet::UserDataTable^  >(__super::Clone()));
        cln->InitVars();
        return cln;
    }
    
    inline ::System::Data::DataTable^  NewDataSet::UserDataTable::CreateInstance() {
        return (gcnew Lesson4::NewDataSet::UserDataTable());
    }
    
    inline ::System::Void NewDataSet::UserDataTable::InitVars() {
        this->columnusername = __super::Columns[L"username"];
        this->columnpassword = __super::Columns[L"password"];
    }
    
    inline ::System::Void NewDataSet::UserDataTable::InitClass() {
        this->columnusername = (gcnew ::System::Data::DataColumn(L"username", ::System::String::typeid, nullptr, ::System::Data::MappingType::Element));
        __super::Columns->Add(this->columnusername);
        this->columnpassword = (gcnew ::System::Data::DataColumn(L"password", ::System::String::typeid, nullptr, ::System::Data::MappingType::Element));
        __super::Columns->Add(this->columnpassword);
        this->columnusername->AllowDBNull = false;
        this->columnpassword->AllowDBNull = false;
    }
    
    inline Lesson4::NewDataSet::UserRow^  NewDataSet::UserDataTable::NewUserRow() {
        return (cli::safe_cast<Lesson4::NewDataSet::UserRow^  >(this->NewRow()));
    }
    
    inline ::System::Data::DataRow^  NewDataSet::UserDataTable::NewRowFromBuilder(::System::Data::DataRowBuilder^  builder) {
        return (gcnew Lesson4::NewDataSet::UserRow(builder));
    }
    
    inline ::System::Type^  NewDataSet::UserDataTable::GetRowType() {
        return Lesson4::NewDataSet::UserRow::typeid;
    }
    
    inline ::System::Void NewDataSet::UserDataTable::OnRowChanged(::System::Data::DataRowChangeEventArgs^  e) {
        __super::OnRowChanged(e);
        {
            this->UserRowChanged(this, (gcnew Lesson4::NewDataSet::UserRowChangeEvent((cli::safe_cast<Lesson4::NewDataSet::UserRow^  >(e->Row)), 
                    e->Action)));
        }
    }
    
    inline ::System::Void NewDataSet::UserDataTable::OnRowChanging(::System::Data::DataRowChangeEventArgs^  e) {
        __super::OnRowChanging(e);
        {
            this->UserRowChanging(this, (gcnew Lesson4::NewDataSet::UserRowChangeEvent((cli::safe_cast<Lesson4::NewDataSet::UserRow^  >(e->Row)), 
                    e->Action)));
        }
    }
    
    inline ::System::Void NewDataSet::UserDataTable::OnRowDeleted(::System::Data::DataRowChangeEventArgs^  e) {
        __super::OnRowDeleted(e);
        {
            this->UserRowDeleted(this, (gcnew Lesson4::NewDataSet::UserRowChangeEvent((cli::safe_cast<Lesson4::NewDataSet::UserRow^  >(e->Row)), 
                    e->Action)));
        }
    }
    
    inline ::System::Void NewDataSet::UserDataTable::OnRowDeleting(::System::Data::DataRowChangeEventArgs^  e) {
        __super::OnRowDeleting(e);
        {
            this->UserRowDeleting(this, (gcnew Lesson4::NewDataSet::UserRowChangeEvent((cli::safe_cast<Lesson4::NewDataSet::UserRow^  >(e->Row)), 
                    e->Action)));
        }
    }
    
    inline ::System::Void NewDataSet::UserDataTable::RemoveUserRow(Lesson4::NewDataSet::UserRow^  row) {
        this->Rows->Remove(row);
    }
    
    inline ::System::Xml::Schema::XmlSchemaComplexType^  NewDataSet::UserDataTable::GetTypedTableSchema(::System::Xml::Schema::XmlSchemaSet^  xs) {
        ::System::Xml::Schema::XmlSchemaComplexType^  type = (gcnew ::System::Xml::Schema::XmlSchemaComplexType());
        ::System::Xml::Schema::XmlSchemaSequence^  sequence = (gcnew ::System::Xml::Schema::XmlSchemaSequence());
        Lesson4::NewDataSet^  ds = (gcnew Lesson4::NewDataSet());
        ::System::Xml::Schema::XmlSchemaAny^  any1 = (gcnew ::System::Xml::Schema::XmlSchemaAny());
        any1->Namespace = L"http://www.w3.org/2001/XMLSchema";
        any1->MinOccurs = ::System::Decimal(0);
        any1->MaxOccurs = ::System::Decimal::MaxValue;
        any1->ProcessContents = ::System::Xml::Schema::XmlSchemaContentProcessing::Lax;
        sequence->Items->Add(any1);
        ::System::Xml::Schema::XmlSchemaAny^  any2 = (gcnew ::System::Xml::Schema::XmlSchemaAny());
        any2->Namespace = L"urn:schemas-microsoft-com:xml-diffgram-v1";
        any2->MinOccurs = ::System::Decimal(1);
        any2->ProcessContents = ::System::Xml::Schema::XmlSchemaContentProcessing::Lax;
        sequence->Items->Add(any2);
        ::System::Xml::Schema::XmlSchemaAttribute^  attribute1 = (gcnew ::System::Xml::Schema::XmlSchemaAttribute());
        attribute1->Name = L"namespace";
        attribute1->FixedValue = ds->Namespace;
        type->Attributes->Add(attribute1);
        ::System::Xml::Schema::XmlSchemaAttribute^  attribute2 = (gcnew ::System::Xml::Schema::XmlSchemaAttribute());
        attribute2->Name = L"tableTypeName";
        attribute2->FixedValue = L"UserDataTable";
        type->Attributes->Add(attribute2);
        type->Particle = sequence;
        ::System::Xml::Schema::XmlSchema^  dsSchema = ds->GetSchemaSerializable();
        if (xs->Contains(dsSchema->TargetNamespace)) {
            ::System::IO::MemoryStream^  s1 = (gcnew ::System::IO::MemoryStream());
            ::System::IO::MemoryStream^  s2 = (gcnew ::System::IO::MemoryStream());
            try {
                ::System::Xml::Schema::XmlSchema^  schema = nullptr;
                dsSchema->Write(s1);
                for (                ::System::Collections::IEnumerator^  schemas = xs->Schemas(dsSchema->TargetNamespace)->GetEnumerator(); schemas->MoveNext();                 ) {
                    schema = (cli::safe_cast<::System::Xml::Schema::XmlSchema^  >(schemas->Current));
                    s2->SetLength(0);
                    schema->Write(s2);
                    if (s1->Length == s2->Length) {
                        s1->Position = 0;
                        s2->Position = 0;
                        for (                        ; ((s1->Position != s1->Length) 
                                    && (s1->ReadByte() == s2->ReadByte()));                         ) {
                            ;
                        }
                        if (s1->Position == s1->Length) {
                            return type;
                        }
                    }
                }
            }
            finally {
                if (s1 != nullptr) {
                    s1->Close();
                }
                if (s2 != nullptr) {
                    s2->Close();
                }
            }
        }
        xs->Add(dsSchema);
        return type;
    }
    
    
    inline NewDataSet::UserRow::UserRow(::System::Data::DataRowBuilder^  rb) : 
            ::System::Data::DataRow(rb) {
        this->tableUser = (cli::safe_cast<Lesson4::NewDataSet::UserDataTable^  >(this->Table));
    }
    
    inline System::String^  NewDataSet::UserRow::username::get() {
        return (cli::safe_cast<::System::String^  >(this[this->tableUser->usernameColumn]));
    }
    inline System::Void NewDataSet::UserRow::username::set(System::String^  value) {
        this[this->tableUser->usernameColumn] = value;
    }
    
    inline System::String^  NewDataSet::UserRow::password::get() {
        return (cli::safe_cast<::System::String^  >(this[this->tableUser->passwordColumn]));
    }
    inline System::Void NewDataSet::UserRow::password::set(System::String^  value) {
        this[this->tableUser->passwordColumn] = value;
    }
    
    
    inline NewDataSet::UserRowChangeEvent::UserRowChangeEvent(Lesson4::NewDataSet::UserRow^  row, ::System::Data::DataRowAction action) {
        this->eventRow = row;
        this->eventAction = action;
    }
    
    inline Lesson4::NewDataSet::UserRow^  NewDataSet::UserRowChangeEvent::Row::get() {
        return this->eventRow;
    }
    
    inline ::System::Data::DataRowAction NewDataSet::UserRowChangeEvent::Action::get() {
        return this->eventAction;
    }
}
