//
// Copyright © 2015 Slack Technologies, Inc. All rights reserved.
//

#include "slack/auth.test.h"
#include "private.h"

namespace slack { namespace auth
{

const std::string test::error::UNKNOWN = std::string{"unknown"};
const std::string test::error::JSON_PARSE_FAILURE = std::string{"json_parse_failure"};
const std::string test::error::INVALID_RESPONSE = std::string{"invalid_response"};
const std::string test::error::NOT_AUTHED = std::string{"not_authed"};
const std::string test::error::INVALID_AUTH = std::string{"invalid_auth"};
const std::string test::error::ACCOUNT_INACTIVE = std::string{"account_inactive"};


test::test()
{
    auto result_ob = slack_private::get(this, "auth.test", {});
    if (!this->error_message)
    {
        if (result_ob["url"].isString()) url = result_ob["url"].asString();
        if (result_ob["team"].isString()) teamname = result_ob["team"].asString();
        if (result_ob["user"].isString()) username = result_ob["user"].asString();
        if (result_ob["team_id"].isString()) team_id = slack::team_id{result_ob["team_id"].asString()};
        if (result_ob["user_id"].isString()) user_id = slack::user_id{result_ob["user_id"].asString()};
    }
}

}} //namespace auth slack