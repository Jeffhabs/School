package com.example.jeffreyhaberle.musicevent;

import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.support.design.widget.FloatingActionButton;
import android.support.design.widget.Snackbar;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.widget.TextView;
import android.widget.Toast;

public class EventListing extends AppCompatActivity {

    private static final String ZIP_CODE_ENTERED = "com.example.jeffreyhaberle.musicevent.enter_zip";
    private String mZipCode;
    private TextView mZipCodeTextView;



    public static Intent newIntent(Context packageContext, String zipCode) {
        Intent i = new Intent(packageContext, EventListing.class);
        i.putExtra(ZIP_CODE_ENTERED, zipCode);
        return i;
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_event_listing);

        mZipCode = getIntent().getStringExtra(ZIP_CODE_ENTERED);
        mZipCodeTextView = (TextView) findViewById(R.id.events_zip_text);

        mZipCodeTextView.setText(mZipCode);
        populateListView();
        registerClickCallBack();
    }

    private void populateListView() {
        //hard code list for testing
        //for JSON api
        String[] myItems = {"The Beatles", "Pink Floyd", "Nirvana", "Lil Wayne"};

        //build adapter
        ArrayAdapter<String> adapter = new ArrayAdapter<String>(this, R.layout.event_list, myItems);

        ListView list = (ListView) findViewById(R.id.listViewMain);
        list.setAdapter(adapter);
    }

    private void registerClickCallBack() {
        ListView list = (ListView) findViewById(R.id.listViewMain);
        list.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View viewClicked, int position, long id) {
               TextView textView = (TextView) viewClicked;
                String message = "You Selected # " + position + ", which is " + textView.getText().toString();

                Toast.makeText(EventListing.this, message, Toast.LENGTH_LONG).show();
            }
        });
    }
}
