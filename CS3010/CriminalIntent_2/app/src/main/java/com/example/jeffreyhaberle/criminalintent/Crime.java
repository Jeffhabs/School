package com.example.jeffreyhaberle.criminalintent;

import java.util.UUID;

/**
 * Created by jeffreyhaberle on 2/21/16.
 */
public class Crime {

    private UUID mId;
    private String mTitle;

    public Crime() {
        //Generate unique identifier
        mId = UUID.randomUUID();
    }

    public UUID getId() {
        return mId;
    }

    public String getTitle() {
        return mTitle;
    }

    public void setTitle(String title) {
        mTitle = title;
    }
}
