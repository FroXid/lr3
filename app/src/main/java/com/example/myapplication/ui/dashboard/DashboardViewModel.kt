package com.example.myapplication.ui.dashboard

import android.content.Intent
import android.os.PowerManager
import android.widget.Toast
import androidx.lifecycle.LiveData
import androidx.lifecycle.MutableLiveData
import androidx.lifecycle.ViewModel
import java.lang.Boolean
import kotlin.String
import kotlin.apply


class DashboardViewModel : ViewModel() {

    private val _text = MutableLiveData<String>().apply {
        value = "This is dashboard Fragment"
    }
    val text: LiveData<String> = _text



}