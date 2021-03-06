/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 * 
 *   http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */


#ifndef PAGESPEED_KERNEL_BASE_COUNTING_WRITER_H_
#define PAGESPEED_KERNEL_BASE_COUNTING_WRITER_H_

#include "pagespeed/kernel/base/basictypes.h"
#include "pagespeed/kernel/base/string_util.h"
#include "pagespeed/kernel/base/writer.h"

namespace net_instaweb {
class MessageHandler;

// Delegates to another writer, but counts bytes along the way.
class CountingWriter : public Writer {
 public:
  explicit CountingWriter(Writer* writer) : byte_count_(0), writer_(writer) { }
  virtual ~CountingWriter();
  virtual bool Write(const StringPiece& str, MessageHandler* handler);
  virtual bool Flush(MessageHandler* handler);
  int byte_count() const { return byte_count_; }

 private:
  int byte_count_;
  Writer* writer_;

  DISALLOW_COPY_AND_ASSIGN(CountingWriter);
};

}  // namespace net_instaweb

#endif  // PAGESPEED_KERNEL_BASE_COUNTING_WRITER_H_
