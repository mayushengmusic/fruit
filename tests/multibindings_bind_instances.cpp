// expect-success
/*
 * Copyright 2014 Google Inc. All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <fruit/fruit.h>
#include <vector>

using fruit::Component;
using fruit::Injector;

struct X {
};

std::vector<X> values = {X(), X()};

fruit::Component<> getComponent() {
  return fruit::createComponent()
    .addInstanceMultibindings(values);
}

int main() {
  
  Injector<> injector(getComponent());
  
  std::vector<X*> multibindings = injector.getMultibindings<X>();
  assert(multibindings.size() == 2);
  assert(multibindings[0] == &(values[0]));
  assert(multibindings[1] == &(values[1]));
  
  return 0;
}
