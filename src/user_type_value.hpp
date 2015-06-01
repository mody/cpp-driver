/*
  Copyright (c) 2014-2015 DataStax

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

  http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.
*/

#ifndef __CASS_USER_TYPE_VALUE_HPP_INCLUDED__
#define __CASS_USER_TYPE_VALUE_HPP_INCLUDED__

#include "abstract_data.hpp"
#include "cassandra.h"
#include "data_type.hpp"
#include "ref_counted.hpp"

namespace cass {

class UserTypeValue : public AbstractData {
public:
  UserTypeValue(const SharedRefPtr<UserType>& user_type)
    : AbstractData(user_type->fields().size())
    , user_type_(user_type) { }

  const SharedRefPtr<UserType>& data_type() const { return user_type_; }

protected:
  virtual size_t get_indices(StringRef name,
                             HashIndex::IndexVec* indices) const {
    return user_type_->get_indices(name, indices);
  }

  virtual const SharedRefPtr<const DataType>& get_type(size_t index) const {
    return user_type_->fields()[index].type;
  }

private:
  SharedRefPtr<UserType> user_type_;

private:
  DISALLOW_COPY_AND_ASSIGN(UserTypeValue);
};

} // namespace cass

#endif
