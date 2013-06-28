#include <v8.h>
#include <node.h>

#include "cgeohash.hpp"
#include "cgeohash_fn.hpp"
#include "cgeohash_obj.hpp"

#ifdef GEOHASH_ENABLE_SPEED_TESTS
#include "cgeohash_fn_repeaters.hpp"
#include "cgeohash_obj_repeaters.hpp"
#endif

void RegisterModule(v8::Handle<v8::Object> target) {
    cgeohash::GeoHashObject::Init(target);
    cgeohash::register_node_fns(target);

#ifdef GEOHASH_ENABLE_SPEED_TESTS
    cgeohash::GeoHashObjectRepeater::Init(target);
    cgeohash::register_node_fn_repeaters(target);
#endif
}

NODE_MODULE(cgeohash, RegisterModule);
