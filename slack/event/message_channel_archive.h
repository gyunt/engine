//
// engine
//
// Copyright © 2015–2016 D.E. Goodman-Wilson. All rights reserved.
//

#pragma once

#include <slack/types.h>
#include <slack/base/event.h>
#include <slack/optional.hpp>
#include <vector>


namespace slack { namespace event
{


struct message_channel_archive : public base::event
{
    static const std::string type;

    virtual std::string str()
    {
        return type;
    }

    message_channel_archive() = default;

    template<class json>
    message_channel_archive(const slack::team_id &team_id, const json &parsed_json);

    slack::user_id user;
    std::string text;
    slack::ts ts;
    std::vector<user_id> members;
};


}} //namespace event slack